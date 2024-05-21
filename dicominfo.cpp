#include <iostream>
#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dctk.h>
#include <dcmtk/dcmdata/dcistrmb.h>  // For DcmInputFileStream
#include <dcmtk/dcmdata/dcistrmf.h>  // For DcmInputFileStream

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <DICOM file>" << std::endl;
        return 1;
    }

    DcmFileFormat fileFormat;
    OFCondition status = fileFormat.loadFile(argv[1]);
    if (!status.good()) {
        std::cerr << "Error: Cannot read DICOM file (" << status.text() << ")" << std::endl;
        return 1;
    }

    DcmDataset *dataset = fileFormat.getDataset();

    // Set the specific character set if needed, or ensure it is interpreting as UTF-8 if specified so.
    OFString charset;
    if (dataset->findAndGetOFString(DCM_SpecificCharacterSet, charset).good()) {
        if (charset.compare("ISO_IR 192") == 0 || charset.compare("UTF-8") == 0) {
            std::cout << "Data is encoded using UTF-8 character set." << std::endl;
        }
    } else {
        std::cout << "No specific character set specified; assuming ISO Latin-1." << std::endl;
    }

    dataset->print(std::cout);

    return 0;
}

# CAN-frame-decoder
Splitting the CAN frame and print the message after decoding. The code is well commented and simple, can be easily understandable.<br />

The main concept of this code is to print the decoded data bytes of CAN frame incase the target ID is matched with ID in CAN frame. <br />
The code is written in C++ and inputs given using command line arguments. The arguments order is strict and target ID and CAN Frame respectively followed.<br />

Instructions for making it to work:<br />
- Commpile the cpp file using your favourite compiler. g++, GCC was used here.<br />
- Run the output **./a.out** file with respective **command line arguments** (as shown in screenshot).<br />
- In case the first argument is available in second argument (strictly at CAN ID) then the data bytes decoded and printed further.<br />


Detailed logic:
- Takes two command line arguments: one is a CAN message in the format **arbitration_id#data_bytes** (e.g., `08FF0300#4D6F62696C697479`), and the other is a target ID (e.g.,`03`).<br />
- Check if the given CAN message is meant for the target ID given as an argument. If that's the case, print the ASCII representation of the data bytes to stdout. Otherwise, print a warning message of your choice to stderr.<br />

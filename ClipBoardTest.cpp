#include <iostream>
#include <string.h>

#include <Application.h>
#include <Clipboard.h>
//#include <Message.h>

//#include "ClipBoardTest.h"

int main()
{
	std::cout << "We are going to read a string from the system ClipBoard!";
	
	const char *string;
	int32 stringLen;
	if (be_clipboard->Lock()) {
	    // Get the clipboard BMessage
	    BMessage *clip = be_clipboard->Data();
 
    	// Read the string from the clipboard data message
    	clip->FindData("text/plain", B_MIME_TYPE, (const void **)&string,
    	&stringLen);
 
    	be_clipboard->Unlock();
	} else
    	fprintf(stderr, "could not lock clipboard.\n");
	
	return 0;
}



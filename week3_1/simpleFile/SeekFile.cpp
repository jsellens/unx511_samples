//SimpleFile.cpp - Performs File I/O
//
// 18-Jan-19  M. Watler         Created.

#include <fcntl.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main()
{
    int fdIn, fdOut;
    int openFlags;
    mode_t filePerms;
    const int BUF_SIZE=1024;
    char buf[BUF_SIZE];
    ssize_t numRead, numWrite;
    int rc=0;

    char inFile[] = "SeekFile.cpp";
    char outFile[]= "SeekFile.bak";

    fdIn = open(inFile, O_RDONLY);
    if(fdIn==-1) {
       cout << "Error opening " << inFile << endl;
       perror("open");
       rc = -1;
    }
    if(rc==0) {
        int err = lseek(fdIn, 100, SEEK_SET);
        if(err==-1) {
            cout << "Error with lseek with " << outFile << endl;
            perror("lseek");
        }

        openFlags = O_CREAT | O_WRONLY | O_TRUNC;
        filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;/* rw-rw-rw- */
        fdOut = open(outFile, openFlags, filePerms);
        if(fdOut==-1) {
           cout << "Error opening " << outFile << endl;
           perror("open");
           close(fdIn);
           rc = -1;
        }
    }

    if(rc==0) {
        do {
           numRead = read(fdIn, buf, BUF_SIZE);
           numWrite = write(1, buf, numRead);
           numWrite = write(fdOut, buf, numRead);
           sleep(1);
           if(numWrite!=numRead) {
               cout << "Could not write the whole buffer. numRead: " << numRead << " numWrite: " << numWrite << endl;
           }
        } while (numRead>0);

        close(fdIn);
        close(fdOut);
        cout << "DONE" << endl;
    }

    return rc;
}

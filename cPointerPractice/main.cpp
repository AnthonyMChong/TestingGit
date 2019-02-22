#include <iostream>
#include <cmath>

std::string intToString ( int convertInt ){
    std::string returnString;
    while ( convertInt > 0){
        returnString +='0' + (convertInt%10);
        convertInt = convertInt/10;
    }
    std::string rs;
    rs.assign(returnString.rbegin(), returnString.rend());
    return rs;
}


char* intToCharArray ( int convertInt ){
    int findMag = convertInt;
    int magCount;
    for (magCount = 0 ; findMag > 0; magCount++){   // first find how many places needed in the char array
        findMag = findMag/10;
    }
    //char* returnCharArray = (char*)malloc( magCount * sizeof(char));
    int numChars = magCount+2;
    char* returnCharArray = (char*)malloc(sizeof(char) * (magCount+2) );    // since function is returning a pointer, use malloc then free so the pointer's contents are not destroyed when exiting scope
    for (int charIndex = 0 ; charIndex < magCount+1 ; charIndex ++){
        returnCharArray[magCount - (charIndex+1)] = (char)('0' + (convertInt%((10))));  // populating the array place by place
        convertInt = convertInt/10;
    }
    printf("%i \n", magCount+1);    // 
    return returnCharArray;
}

// smaple function to make sure I get malloc sizing correct
char * createStr() {

    char char1= 'm';
    char char2= 'y';

    char *str = (char *) malloc(sizeof(char) * 3);
    str[0] = char1;
    str[1] = char2;
    str[2] = '\0';

    return str;

}

// converting ints into strings/char arrays MANY different ways! definately some easier than others...
int main(){
    int myInt = 54321;
    // function that does some straight forward string manipulation
    std::cout << intToString(myInt) << std::endl;

    // function that does not use any std::string method... a bit too complicated for my taste
    char* returnedCharArray = intToCharArray(myInt);
    char* createStrTEST = createStr();
    //std::cout << returnedCharArray << std::endl;
    printf("%s \n", returnedCharArray);
    for ( int arrayIndex = 0 ; arrayIndex <= sizeof(returnedCharArray)/sizeof(*returnedCharArray) ; arrayIndex++){
        printf("%c", (char)returnedCharArray[arrayIndex]);
    }
    free(returnedCharArray);

    // yea... def would use this method over ALL OTHERS!!!
    std::cout <<'\n' << std::to_string(myInt).c_str() << std::endl;
}


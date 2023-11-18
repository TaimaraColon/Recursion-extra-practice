#include <iostream>
#include <vector>

using namespace std;

/*
    *+*+*+*+*+* Find the minimum value of a vector using recursion *+*+*+*+*
         ! Return the value at index ! ! Use a helper function !
*/

int findMinimumValueHelper(vector<int>v, int index,int minimumValue){
    
    if(index == v.size()){   //passed the end of the vector 
        return minimumValue;
    }
      //recursive step
    if(v[index] < minimumValue){     //checks for the minimum value
        minimumValue = v[index];
    }
    return findMinimumValueHelper(v, index + 1, minimumValue);   //moves through the vector
  
}

int findMinimumValue(vector<int>v){
    if(v.empty()){    // check if vector is empty
        return -1;
    }
    return findMinimumValueHelper(v, 0, v[0]); //search starts at the first element
}


/*
    *+*+*+*+*+* Find the given target of a vector using recursion *+*+*+*+*
         ! Return its index ! ! Use a helper function ! ! Return -1 if empty !
*/

int findTargetHelper(vector<string>v, string target, int index){
    if(v.size() == index){   //target not found
        return -1;
    }
    if(v[index] == target){   //target found
        return index;
    }
    return findTargetHelper(v,target,index+1);  //go to the next
}

int findTarget(vector<string>v, string target){
    return findTargetHelper(v,target,0);  //search starts at 0
}



int main(){
    /*  TEST CASES  */
    
    //FIND MINIMUM VALUE
    vector<int>test1;
    vector<int>test2;
    vector<int>test3;
    vector<int>test4;
    test1 = {6,10,2,4,3,5,7,8,1,9};
    test2 = {9,6};
    test3 = {3};
    test4 = {};

    cout << "Find minimum value Test 1: " << findMinimumValue(test1) << endl; //1
    cout << "Find minimum value Test 2: " << findMinimumValue(test2) << endl; //6
    cout << "Find minimum value Test 3: " << findMinimumValue(test3) << endl; //3
    cout << "Find minimum value Test 4: " << findMinimumValue(test4) << endl; //-1

    //FIND TARGET INDEX
    vector<string>test5;
    vector<string>test6;
    vector<string>test7;
    vector<string>test8;
    vector<string>test9;
    test5 = {"koala", "dog", "shark", "chicken"};
    test6 = {""};
    test7 = {"INSO"};
    test8 = {"cat","tiger"};
    test9 = {"ICOM","CIIC", "INSO"};

    cout << "FIND TARGET INDEX" << endl;
    cout << "Find target Test 5: " << findTarget(test5,"koala") << endl; //0
    cout << "Find target Test 6: " << findTarget(test6, "boo") << endl; //-1
    cout << "Find target Test 7: " << findTarget(test7, "ICOM") << endl; //-1
    cout << "Find target Test 8: " << findTarget(test8, "tiger") << endl; //1
    cout << "Find target Test 9: " << findTarget(test9, "INSO") << endl; //2
}
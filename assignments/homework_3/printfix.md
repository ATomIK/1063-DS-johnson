```cpp
/**
* @Homework: Homework-3
* @Author: Thomas Johnson
* @Description:
*     This snippet is a fix for our main program's print method.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 02 28 2017
*/

/**
* @FunctionName: Print
* @Description:
*     If front is the same as rear, then it's full/empty so just loop through it.
*	  If it's empty then it won't print anything.
* @Params:
*    NONE
* @Returns:
*    NONE
*/
void Print() {
	if (Front == Rear) {
		for (int i = 0; i < NumItems; i++) {
			cout << Q[i] << " ";
		}
	}
	else {
		int Index = Front;
		while (Index != Rear) {
			cout << Q[Index] << " ";
			Index = ((Index + 1) % (ArraySize));
		}
	}

	cout << endl;
}
```


int Passes;
int Fails;

// Add elements with AddElements and remove head then check if the added and removed elements were the same 
int BlackBox1(struct circularBuffer *bufferPtr, int value);

/*Add one element, add another element (with different value), remove one
element, remove one element. Check that added and removed elements are
in same order.*/ 
int BlackBox2(struct circularBuffer* bufferPtr, int valueToAdd1, int valueToAdd2, int valueToRemove1, int valueToRemove2);

/*Add BUFFER_SIZE number of differeny elements in sequence, and remove
BUFFER_SIZE elements. Check that added and removed elements are in
same order.*/
int BlackBox3(struct circularBuffer* bufferPtr,int BUFFER_SIZE);

/*Add BUFFER_SIZE+1elements. Check that function failed or that last
element overwrites the first added element, depending on your choice of
functionality.*/
int BlackBox4(struct circularBuffer* bufferPtr, int value1, int value2, int value3, int value4, int value5, int value6);

/*Repeat test 1 BUFFER_SIZE+1 times. Check that added and removed
elements are in same order.*/
int BlackBox5(struct circularBuffer* bufferPtr, int BUFFER_SIZE);

/*Run contains() on empty buffer. Check that it returns value INT_MIN.*/
int BlackBox6(struct circularBuffer* bufferPtr,int value);

/*Add one element. Check that buffer contains an element with the added
value.*/
int BlackBox7(struct circularBuffer* bufferPtr, int value);
/*Add two elements. Check that the buffer contains the value of the second
element you added.*/
int BlackBox8(struct circularBuffer* bufferPtr, int value1, int value2);

/*Add BUFFER_SIZE elements with different values. Check that the buffer
contains the value of the last element you added.*/
int BlackBox9(struct circularBuffer* bufferPtr,int BUFFER_SIZE);

//Prints out the tests results
void Results();



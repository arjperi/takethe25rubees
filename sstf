void sstf()
{
	int head;	//disk head.
	head = 46;  // this will change, you will get it from the threads.
	vector<int> trackNum;
	int currentTrack;
	currentTrack = head;
	trackNum.push_back(123);
	trackNum.push_back(205);
	trackNum.push_back(1);
	trackNum.push_back(87);
	int numDiskEntries = trackNum.size();
	//looping variable
	int whileIterator = numDiskEntries;
	// intermediate values store in this array
	int interVal[numDiskEntries];
	while(whileIterator != 0)
	{
        	for (int it1 = 0; it1 < numDiskEntries ; it1++)
        	{
            		//populate the intermediate array with difference values
            		interVal[it1] = abs(trackNum.at(it1)-currentTrack);
        	}
        	int smallIndex = getIndexOfSmallestElement(interVal,numDiskEntries);   //get index of the smallest seek value
        	currentTrack = trackNum.at(smallIndex);
        	//cout << "current position " << currentTrack << endl;
        	trackNum.erase(trackNum.begin()+smallIndex);
        	numDiskEntries = trackNum.size();
        	int interVal[numDiskEntries];
        	whileIterator--;
    	}
}

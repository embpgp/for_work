/*
 *Filename:SecondMaxNum.c
 *
 *Description:find the second max number in a array
 *
 *Author:rutk1t0r
 *
 *Date:2016.10.12
 *
 *GPL
 *
 */

int find_second_max(const int* data,const int count)
{
	if (data == NULL || !count || count == 1)
		return -1;
	
	int maxVal = data[0] > data[1] ? data[0] : data[1];  //Max
	int smaxVal = data[0] + data[1] - maxVal;   //second
	
	for (int i = 2;i < count;i++)
	{
		if (data[i] > maxVal)
		{
			smaxVal = maxVal;
			maxVal = data[i];
		}
		else if (data[i] < maxVal && data[i] > smaxVal)
		{
			smaxVal = data[i];
		}
			
	}
	
	return smaxVal;
}


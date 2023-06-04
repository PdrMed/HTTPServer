#pragma once
// legacy PT decode

static int DecodeCompress(BYTE* lpSrcData, BYTE* lpDestData, int dCount)
{
	int DecCounter;
	int cnt;
	int Counter;
	int size;
	int len;

	size = ((int*)lpSrcData)[0];

	Counter = 4;
	DecCounter = 0;

	while (1)
	{
		if (Counter >= size) break;
		if (lpSrcData[Counter] & 0x80)
		{
			len = lpSrcData[Counter++] & 0x7F;
			for (cnt = 0; cnt < len; cnt++)
			{
				if (DecCounter >= dCount) return Counter;
				lpDestData[DecCounter++] = 0;
			}
		}
		else
		{
			len = lpSrcData[Counter++] & 0x7F;
			for (cnt = 0; cnt < len; cnt++)
			{
				if (DecCounter >= dCount) return Counter;
				lpDestData[DecCounter++] = lpSrcData[Counter++];
			}
		}
	}

	return Counter;
}

static int DecodeCompress(BYTE* lpSrcData, BYTE* lpDestData)
{
	return DecodeCompress(lpSrcData, lpDestData, 0x7FFFF);
}
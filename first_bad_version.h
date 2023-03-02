#pragma once

/*
Created: 27-02-23

278. First Bad Version [Easy]
You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. 
You should minimize the number of calls to the API.

Example 1:
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.

Example 2:
Input: n = 1, bad = 1
Output: 1
*/

class FirstBadVersion
{
public:

	FirstBadVersion(int version)
		: m_version(version)
	{

	}

	bool isBadVersion(int version)
	{
		if (version >= m_version)
			return true;

		return false;
	}

	int firstBadVersion(int n);
	int firstBadVersion2(int n);
	
private:

	int m_version;
};


int FirstBadVersion::firstBadVersion(int n)
{
	int last = n;
	bool fail = false;

	for (int i = n; i > 0; i--)
	{
		if (isBadVersion(i) == false && fail)
			return last;
		else
		{
			last = i;
			fail = true;
		}

	}

	return last;
}

int FirstBadVersion::firstBadVersion2(int n)
{
	int mid;
	int last = 0;
	int e = 1;
	int d = n;

	while (e <= d)
	{
		mid = e + (d - e) / 2;
		if (isBadVersion(mid))
		{
			last = mid;
			d = mid - 1;
		}
		else
		{
			e = mid + 1;
		}
	}

	return last;
}

/*
	FirstBadVersion f1(4);
	int v1 = f1.firstBadVersion2(5);         // 4

	FirstBadVersion f2(1);
	int v2 = f2.firstBadVersion2(1);         // 1

	FirstBadVersion f3(1);
	int v3 = f3.firstBadVersion2(3);         // 1

	FirstBadVersion f4(2);
	int v4 = f4.firstBadVersion2(2);         // 2

	FirstBadVersion f5(1);
	int v5 = f5.firstBadVersion2(2);         // 1

	FirstBadVersion f7(1702766719);
	int v6 = f7.firstBadVersion2(2126753390);
*/
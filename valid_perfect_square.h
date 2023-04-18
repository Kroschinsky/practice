#pragma once

/*
367. Valid Perfect Square [Easy]

Given a positive integer num, return true if num is a perfect square or false otherwise.
A perfect square is an integer that is the square of an integer.In other words, it is the product of some integer with itself.
You must not use any built - in library function, such as sqrt.

Example 1:
Input: num = 16
Output : true
Explanation : We return true because 4 * 4 = 16 and 4 is an integer.

Example 2 :
Input : num = 14
Output : false
Explanation : We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.

Constraints :
1 <= num <= 231 - 1
*/

bool isPerfectSquare(int num) 
{
	if (num == 1)
		return true;

	long long ntry = num;
	long long check = 0;

	while (true)
	{
		ntry = ntry / 2;
		if (ntry == 0)
			return false;

		check = ntry * ntry;

		if (check == num)
			return true;
		else if (check < num)
			break;
	}

	while (true)
	{
		ntry++;
		check = ntry * ntry;

		if (check == num)
			return true;
		else if (check > num)
			break;
	}

	return false;
}

bool isPerfectSquare2(int num)
{
	int i = 1;
	while (num > 0) 
	{
		num -= i;
		i += 2;
		if (!num) 
			return true;
	}

	return false;
}

bool isPerfectSquare3(int num)
{
	long long l = 1;
	long long r = num;
	long long mid = 0;
	long long calc = 0;

	while (l <= r)
	{
		mid = (l + r) / 2;
		calc = mid * mid;

		if (calc > num)
			r = mid - 1;
		else if (calc < num)
			l = mid + 1;
		else
			return true;
	}

	return false;
}


/*
	bool b1 = isPerfectSquare2(16);
	bool b2 = isPerfectSquare2(14);
	bool b3 = isPerfectSquare2(49);
	bool b4 = isPerfectSquare2(1);
	bool b5 = isPerfectSquare2(2);
	bool b6 = isPerfectSquare2(5);
*/
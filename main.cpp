/*
 * main.cpp
 *
 *  Created on: 3 Dec 2016
 *      Author: Matusovsky
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

vector<double> people;
vector<double> combination;
vector<vector<double> > archive, cmb1, cmb2;
vector<double> sum1, sum2;

static unsigned int count = 0;
static unsigned int MaxDifference = 1000000L;

void pretty_print(const vector<double>& v)
{
  cout << "combination no " << count << ": [ ";

  archive.push_back(v);

  for (unsigned int i = 0; i < v.size(); ++i)
  {
	  cout << v[i] << " ";
  }

  count++;

  cout << "] " << endl;
}

void go(int offset, int k)
{
  if (k == 0)
  {
	pretty_print(combination);
	return;
  }
  for (unsigned int i = offset; i <= people.size() - k; ++i)
  {
    combination.push_back(people[i]);
    go(i+1, k-1);
    combination.pop_back();
  }
}

void to_sums(vector<vector<double> >& v, vector<double>& s)
{
	for (vector<vector<double> >::iterator it = v.begin() ; it != v.end(); ++it)
	{
		double sum = 0.0;
		vector<double> tmp = *it;

		for (unsigned int i = 0; i < tmp.size(); i++)
	    	sum += tmp[i];

	    s.push_back(sum);
	}
}

void to_pair(vector<vector<double> >& v, vector<double>& s, unsigned int k)
{
	unsigned int idx = 0;

	for (vector<vector<double> >::iterator it = v.begin() ; it != v.end(); ++it, idx++)
	{
		if (idx == k)
		{
			vector<double> tmp = *it;

			cout << "\nCombination: [ ";
			for (unsigned int i = 0; i < tmp.size(); i++)
				cout << " " << tmp[i];
			cout << " ] SUM=" << s[k] << "\n";
			break;
		}
	}
}

int main() {
  int n = 5, k = 3;

  double arr1[] = {0.1, 0.5, 0.7, 0.45, 0.12};
  double arr2[] = {0.18, 0.61, 0.44, 0.1, 0.2};

  cout << "Input k: ";
  cin >> k;
  cout << "Input n: ";
  cin >> n;
  cout << "Input numbers for array 1: ";
  cin >> arr1[0] >> arr1[1] >> arr1[2] >> arr1[3] >> arr1[4];
  cout << "Input numbers for array 2: ";
  cin >> arr2[0] >> arr2[1] >> arr2[2] >> arr2[3] >> arr2[4];

  cout << "Input Array1: [ ";
  for (unsigned int i = 0; i < sizeof(arr1)/sizeof(double); i++)
	cout << " " << arr1[i];
  cout << " ]\n";

  cout << "Input Array2: [ ";
  for (unsigned int i = 0; i < sizeof(arr2)/sizeof(double); i++)
	cout << " " << arr2[i];
  cout << " ]\n\n";

  for (int i = 0; i < n; ++i)
	  people.push_back(arr1[i]);

  for (int h = k; h <= n; h++)
     go(0, h);

  count = 0;

  cmb1.swap(archive);

  for (int i = 0; i < n; ++i)
	  people.pop_back();

  for (int i = 0; i < n; ++i)
	  people.push_back(arr2[i]);

  for (int h = k; h <= n; h++)
     go(0, h);

  cmb2.swap(archive);

  // Create vectors of sums in corresponding (to cmb1 or cmb2) locations
  to_sums(cmb1, sum1);
  to_sums(cmb2, sum2);

  //Permutation of sum1 and sum2
  double tmp_min, min = MaxDifference;
  unsigned int min_i = 0, min_j = 0;
  for (unsigned i = 0; i < sum1.size(); i++)
  {
	  for (unsigned j = 0; j < sum2.size(); j++)
	  {
		  tmp_min = fabs(sum1[i] - sum2[j]);
		  if (tmp_min < min)
		  {
			  min = tmp_min;
			  min_i = i;
			  min_j = j;
		  }
	  }
  }

  // Print minimal difference pairs from both arrays
  to_pair(cmb1, sum1, min_i);
  to_pair(cmb2, sum2, min_j);

  if (sum2[min_j])
	  cout << "\nProportion is " << sum1[min_i]/sum2[min_j] << "\n";
  else
	  cout << "\nResults are invalid: " << sum1[min_i] << "," << sum2[min_j] << "\n";

  return 0;
}


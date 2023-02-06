#include<iostream>
#include<map>
#include<string>

using namespace std;

string s;
string maxS, minS;
int maxN, minN = 3001;
//string ss;
int si;

string change(string a)
{
	//mmmk
	int tmpSize = a.size();
	string tt = "";
	if (a[tmpSize - 1] == 'K')
		tt += "5";
	else
		tt += "1";
	for (int i = tmpSize - 2; i >= 0; i--)
		tt += "0";

	//cout << tt << endl;
	return tt;
}

void makeMaxNum(string tmp, string ss, int idx)//변환한 문자열, 변환전 컷팅한 문자열, 어디까지 변환했는지 인덱스
{


	if (idx == si)//끝까지 다 변환
	{

		if (ss.size() > 0)
		{
			bool chk = false;
			string ttt = "";
			for (int i = 0; i < ss.size(); i++)
			{
				if (ss[i] == 'K')
					chk = true;
				ttt += "1";
			}
			if (chk)
				tmp += change(ss);
			else
				tmp += ttt;
		}
		if (tmp.size() != si)
			return;

		int tempN = tmp.length();

		if (tempN > maxN)
		{
			maxN = tempN;
			maxS = tmp;

		}
		else if (tempN == maxN)
		{
			//길이가 같으면 사전순 비교

			if (tmp > maxS)
			{
				maxN = tempN;
				maxS = tmp;

			}
		}

		return;
	}



	if (s[idx] != 'K')
	{

		makeMaxNum(tmp, ss + s[idx], idx + 1);


	}
	else
	{

		makeMaxNum(tmp + change(ss + s[idx]), "", idx + 1);



	}





}

void makeMinNum(string tmp, string ss, int idx)//변환한 문자열, 변환전 컷팅한 문자열, 어디까지 변환했는지 인덱스
{

	if (idx == si)//끝까지 다 변환
	{

		if (ss.size() > 0)
			tmp += change(ss);
		if (tmp.size() != si)
			return;

		int tempN = tmp.length();

		if (tempN < minN)
		{
			minN = tempN;
			minS = tmp;
		}
		else if (tempN == minN)
		{
			//길이가 같으면 사전 순 비교

			if (tmp < minS)
			{
				minN = tempN;
				minS = tmp;
			}
		}
		return;
	}



	if (s[idx] == 'M')
	{
		makeMinNum(tmp, ss + s[idx], idx + 1);


	}
	else
	{
		if (ss.size() > 0)
		{
			tmp += change(ss);
		}
		tmp += "5";
		makeMinNum(tmp, "", idx + 1);


	}



}




int main()
{


	cin >> s;

	
	string t = "";
	si = s.length();
	string ss = "";
	bool chk = true, chk2 = true;
	for (int i = 0; i < si; i++)
	{
		if (s[i] == 'K')
			chk = false;
		if (s[i] == 'M')
			chk2 = false;
		minS += "5";
		maxS += "1";
	}
	minS = maxS;
	if (chk)
		maxN = si;
	if (chk2)
		maxS = si;

	makeMaxNum(t, ss, 0);
	makeMinNum(t, ss, 0);

	cout << maxS << "\n" << minS << endl;

}

//void makeNum(string tmp, string ss, int idx)//변환한 수, 변환전 컷팅한 수, 어디까지 변환했는지 인덱스
//{
//	//	cout << endl;
//	cout << "=================" << endl;
//	cout << "tmppp " << tmp << endl;
//	cout << "ssss  " << ss << endl;
//	cout << "idxxx " << idx << endl;
//	cout << "=================" << endl;
//	//cout << endl;
//	//cout << "tmp.size" << tmp.size() << endl;
//	//cout << endl;
//	if (idx == si)//끝까지 다 변환
//	{
//		cout << "xxxx          " << ss << endl;
//
//		if (tmp.size() != si)
//			return;
//		cout << "답 " << tmp << endl;
//		int tempN = tmp.length();
//		cout << tempN << " " << maxN << endl;
//		if (tempN > maxN)
//		{
//			maxN = tempN;
//			maxS = tmp;
//			cout << maxS << endl;
//		}
//		else if (tempN == maxN)
//		{
//			//길이가 같으면 사전순 비교
//			cout << "사전순 " << tmp << "  " << maxS << endl;
//			if (tmp > maxS)
//			{
//				maxN = tempN;
//				maxS = tmp;
//				cout << "max  " << maxS << endl;
//			}
//		}
//		if (tempN < minN)
//		{
//			minN = tempN;
//			minS = tmp;
//		}
//		else if (tempN == minN)
//		{
//			//길이가 같으면 사전 순 비교
//			cout << "작은거 " << tmp << endl;
//			if (tmp < minS)
//			{
//				minN = tempN;
//				minS = tmp;
//			}
//		}
//		return;
//	}
//	//if (ss.size() > 1&&ss[ss.length()-1]!='k')
//	//{
//	//	cout<<"--------------------------" << endl;
//	//	cout <<"여기          " << ss << "  " << tmp << endl;
//	//	//tmp += change(ss);
//	//	if (ss[ss.size() - 1] == 'K')
//	//	{
//	//	
//	//		ss = "";
//	//	}
//	//	cout << tmp << endl;
//	//
//	//	cout << "--------------------------" << endl;
//	//	
//	////	return;
//	//}
//
//	if (s[idx] == 'K' && ss.size() == 0)
//		makeNum(tmp + "5", "", idx + 1);
//	else if (s[idx] == 'K')
//	{
//		//cout << "ddddddddddddddddddddddddddddddddddddddddddddddd" << endl;
//
//		//cout << tmp << endl;
//		//cout << "킹받아 " << tmp+ change(ss + s[idx]) << endl;
//		//makeNum(tmp+change(ss+s[idx]) ,"", idx + 1);
//		//cout<<"여깅" << tmp << "   " << tmp + change(s[idx]) << endl;
//		makeNum(change(ss + s[idx]), "", idx + 1);
//
//
//	}
//	else
//	{
//		cout << "111111111111111111ddddddddddddddddddddddddddddddddddddddddddddddd" << endl;
//		//	cout<<"ss  "<< ss<<"    " << ss + s[idx] << "  idx  " << idx << endl;
//
//		makeNum(change(ss + s[idx]), ss + s[idx], idx + 1);
//		makeNum(change(ss + s[idx]), "", idx + 1);
//
//		ss = "";
//		cout << ss << endl;
//		makeNum(tmp + "1", ss, idx + 1);
//
//	}
//
//
//
//
//
//}
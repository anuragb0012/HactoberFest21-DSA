//https://leetcode.com/problems/daily-temperatures

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures){
		vector<int> dt,dt_ind,val;
		for(unsigned i=0;i<temperatures.size();i++)
		{
			val.push_back(0);
			if(i==0)
			{
				dt.push_back(temperatures[0]);
				dt_ind.push_back(0);
			}
			else
			{
				if(temperatures[i]>dt[dt.size()-1])
				{
					while(dt.size()>0 && (temperatures[i]>dt[dt.size()-1]))
					{
						val[dt_ind[dt_ind.size()-1]]=i-(dt_ind[dt_ind.size()-1]);
						dt_ind.pop_back();
						dt.pop_back();
					}
					dt.push_back(temperatures[i]);
					dt_ind.push_back(i);
				}
				else
				{
					dt.push_back(temperatures[i]);
					dt_ind.push_back(i);
				}
			}
		}
		return val;
	}
};
#include<bits/stdc++.h>
using namespace std;

int unit_water(vector<int> hei, int begin, int end)
    {
        int min_hei = min(hei[begin], hei[end]);
        
        int i = begin+1;
        int water_units = 0;

        while((min_hei - hei[i]) >= 0 && i<=end)
        {
            water_units = water_units + (min_hei - hei[i]);
            i++;
        }
        return water_units;
    }

int trap(vector<int>& height) {
        if(height.size() == 1)
            return 0;
        
        int size = height.size();
        
        int excl;
        for(excl = 0; excl < size; excl++)
        {
            if(height[excl] == 0)
            {
                continue;
            }
            else{
                break;
            }
        }
        
        int water = 0;
        for(int i = excl; i<size-1; i++)
        {
            int start = 0;
            int end = 0;
            if((height[i] < height[i+1])) continue;
            else
            {
                start = i;
                int st_hei = height[start];
                vector<int> heights;
                while(i<size-1 && height[i] >= height[i+1]){
                    heights.push_back(height[i]);
                    i++;
                }  
                sort(heights.begin(), heights.end());
                int intermediate = i;
                bool first = false;
                if(intermediate-1 == start)
                {
                    first = true;
                }
                
                bool found = false;
                for(int j = heights.size()-1; j>=0; j--)
                {
                    while(intermediate<size && height[intermediate] < heights[j])
                    {
                        intermediate++;
                    }
                    if(height[intermediate] >= heights[j] && intermediate != size)
                    {
                        end = intermediate;
                        water = water + unit_water(height, start, end);
                        found = true;
                    }
                    else if(intermediate == size && !first)
                    {
                        intermediate = i;
                        continue;
                    }
                    else if(intermediate == size)
                    {
                        intermediate = start+1;
                        while(intermediate<size-1 && height[intermediate] < height[intermediate+1])
                        {
                            intermediate++;
                        }
                        end = intermediate;
                        water = water + unit_water(height, start, end);
                        found = true;
                    }
                    if(found == true)
                    {
                        i = end-1;
                        break;
                    }
                }
            }
            if(i==size-1) break;
        }
        return water;
    }

int main()
{
    // vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1,1,3};  --> 13 units
    // vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};  --> 6 units
    // vector<int> vec = {2,0,2};  --> 2 units
    // vector<int> vec = {9,4,5};  --> 1 unit
    // vector<int> vec = {14,2,3,4,2,3}; --> 4 units
    // vector<int> vec = {14,10,9,8,3,3};  --> 0 units
    // vector<int> vec = {14,10,9,8,3,4};  --> wrong answer .. should be 1
    vector<int> vec = {14,10,9,8,3,4}; 
    // vector<int> vec = {4,2,0,3,2,5}; --> 9 units
    // vector<int> vec = {0,4,5,6,4,3,2,4,6,8,2,6};  --> 15 units
    
    
    int answer = trap(vec);
    cout<<"Answer: "<<answer;
    return 0;
}







/*

for(int j = heights.size()-1; j>=0; j--)
                {
                    cout<<"j value: "<<j<<" and heights vec value: "<<heights[j]<<" and water stored: "<<water<<endl;
                    while(intermediate<size && height[intermediate] < heights[j])
                    {
                        intermediate++;
                    }
                    cout<<"Abhi intermediate: "<<intermediate<<" start: "<<start<<endl;
                    if(height[intermediate] >= heights[j] && intermediate != size)
                    {
                        cout<<"Abhishek inside if: "<<intermediate<<endl;
                        end = intermediate;
                        cout<<"Start: "<<start<<" end: "<<end<<" Water: "<<water<<endl;
                        water = water + unit_water(height, start, end);
                        cout<<"Water: "<<water<<endl;
                        found = true;
                    }
                    else if(intermediate == size && !first)
                    {
                        intermediate = i;
                        cout<<"Abhi: "<<intermediate<<endl;
                        continue;
                    }
                    else if(intermediate == size)
                    {
                        intermediate = start+1;
                        while(intermediate<size-1 && height[intermediate] < height[intermediate+1])
                        {
                            intermediate++;
                        }
                        end = intermediate;
                        cout<<"Starttt: "<<start<<" end: "<<end<<endl;
                        water = water + unit_water(height, start, end);
                        found = true;
                    }
                    if(found == true)
                    {
                        i = end-1;
                        break;
                    }
                }

*/
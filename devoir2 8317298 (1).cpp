using namespace std;
#include <iostream>
//Cheryl Tollola
//8317298
    

int main()
{
    float an19[12][3] = {{-15,-12,-9},{-12,-9,-6},{-8,-4,-1},{1,5,9},{7,11,15},{12,17,22},{17,22,27},{14,19,24},{10,15,20},{5,9,13},{-5,-2,2},{-7,-4,-1}};
    float an18[12][3] = {{-13,-9,-5},{-9,-5,0},{-4,-1,2},{-1,3,7},{8,15,21},{12,17,23},{17,22,28},{17,21,26},{12,17,21},{3,7,11},{-4,-1,2},{-8,-5,-2}};
    float an17[12][3] = {{-11,-7,-3},{-11,-6,-2},{-9,-6,-2},{3,7,11},{7,11,16},{12,17,22},{15,20,25},{13,19,24},{13,18,23},{9,13,17},{-3,1,5},{-11,-9,-6}};
    float an16[12][3] = {{-11,-7,-4},{-13,-9,-4},{-6,-2,1},{-1,3,8},{8,13,18},{12,17,22},{15,20,25},{16,21,26},{11,17,22},{6,9,13},{0,4,7},{-9,-6,-2}};
    float an15[12][3] = {{-18,-13,-8},{-22,-17,-12},{-10,-6,-2},{1,5,10},{9,15,22},{11,17,22},{14,20,26},{15,20,25},{12,17,22},{4,8,12},{2,5,8},{-1,1,4}};
    float an14[12][3] = {{-17,-12,-8},{-16,-11,-7},{-12,-8,-3},{0,4,8},{7,13,18},{12,17,23},{13,18,24},{13,18,24},{10,15,20},{6,10,14},{-2,1,4},{-6,-4,-1}};
    float an13[12][3] = {{-15,-10,-5},{-14,-10,-5},{-6,-3,0},{0,4,9},{8,13,19},{11,16,21},{15,20,26},{13,19,25},{8,14,19},{6,9,13},{-5,-1,3},{-13,-9,-6}};
    float an12[12][3] = {{-14,-9,-5},{-12,-7,-2},{-1,3,7},{1,6,10},{9,14,20},{12,18,23},{14,20,25},{15,19,24},{9,14,19},{6,10,14},{-2,1,4},{-8,-5,-1}};
    float an11[12][3] = {{-14,-11,-7},{-13,-9,-4},{-7,-4,0},{1,5,10},{7,12,17},{12,17,22},{15,21,26},{14,19,23},{11,16,20},{6,10,13},{1,5,9},{-6,-3,0}};
    float an10[12][3] = {{-10,-7,-4},{-7,-5,-3},{-1,3,6},{4,9,14},{8,14,20},{12,17,22},{16,21,26},{14,19,24},{10,15,19},{4,8,11},{-2,2,5},{-8,-6,-3}};
    
    //Array to hold the average, min and max statistics
    float stats[12][3];

        //temp: Array of size 10 of pointers to multidimensional arrays size [12][3]
    float (*temp[10])[12][3] = {&an19,&an18,&an17,&an16,&an15,&an14,&an13,&an12,&an11,&an10};

    // chose arbitrary initial max and min numbers from year 19 as reference 
    // initiaize stats w default values
    float (*pMonthStat)[3] = stats;
    float (*pAn19)[3] = an19;
    while(pMonthStat!=(stats + 12) && pAn19 != an19+12)
    {
        *(*pMonthStat)=  *(*pAn19+0); // initiaize min
        *(*pMonthStat+1)=  0; // intialize moy
        *(*pMonthStat+2)=  *(*pAn19+2); // intialize max
        pMonthStat++;
        pAn19++;
    }
    
    //pYear is a pointer to an array of size [12][3]
    for (float (* pYear)[12][3] = *temp; pYear != *temp  +10; pYear ++)
    {
        int month = 0;
        
        //pMonth is a pointer to an array of size [3]
        for (float (*pMonth)[3] = *pYear; pMonth != *pYear + 12; pMonth ++)
        {
            int index = 0;
            
            //pStat is a pointer to a float number
            for (float *pStat = *pMonth; pStat != *pMonth + 3; pStat ++)
            {
                float *stat = *(stats+month)+index; // this maps to stats[month][index]
                if(index==0)
                {
                    *stat = (*pStat <= *stat ) ? *pStat : *stat;
                }
                else if(index==1)
                {
                    *stat += *(pStat)/10;
                }
                else if(index==2)
                {
                     *stat = (*pStat >= *stat) ? *pStat : *stat;
                }
                index++;

            }
            month++;
        }
        
    }
    
    int counter = 1;

    for(float (*pMonth)[3] = stats; pMonth != stats + 12; pMonth ++,counter++)
    {
        std::cout << " Statistics sur le mois "<<  counter << ": temp min: "<< *(*pMonth)<< ": temp moy: "<< *(*pMonth+1) << ": temp max: "<< *(*pMonth+2)<< endl;
    }

    

    return 0;
}








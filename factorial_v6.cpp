/*
	This program finds the factorial for a given number of any size.
*/

#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<tuple>

std::tuple<double,double> fnFactorial(double lNumForFactorial)
{
  double aFactorialOfNum=1, old_aFactorialOfNum, old_lNumForFactorial;
  
  int i=1;


  if(lNumForFactorial>1)
  {
    do
    {
	  old_aFactorialOfNum=aFactorialOfNum;
	  old_lNumForFactorial=lNumForFactorial;
	  
      aFactorialOfNum*=lNumForFactorial;

      if(std::isinf(aFactorialOfNum))
         break;

      lNumForFactorial-=1;
      i+=1;
    } while(lNumForFactorial>0); 
  }
  else
    aFactorialOfNum=1;
	
  return std::make_tuple(old_aFactorialOfNum, old_lNumForFactorial);
}



int main(void)
{
  double lNumForFactorial;
  
  do
  { 
    std::cout<<"\nEnter the number to find the factorial: ";
    std::cin>>lNumForFactorial;
  
    if(lNumForFactorial<0)
       std::cout<<"\n\nKindly enter a postive integer number for algorithm to be effective. Thanks.";
    else
       break; 
  } while(1);

  double lOriginalNum=lNumForFactorial;
  
  double remaining_Iterations=0, current_Result, temp, loop_Count=0;
  
  std::cout<<"\n"<< lOriginalNum <<"! = ";
  do
  {
	
	std::tie(current_Result, remaining_Iterations)=fnFactorial(lNumForFactorial);
  
    if(remaining_Iterations>=1)
	  std::cout<<current_Result <<" * ";      
	  
	lNumForFactorial=remaining_Iterations;

	
  }while(remaining_Iterations>1);	
  
  std::cout<<"1\n\n";
  
  return(0);

}

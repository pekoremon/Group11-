#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;




int main(){
	int age;
	int retireAge;
	int lifeExpectancy;
	double currentSavings;
	double AnnualRetireContribu;
	double annualReturnRate;
	double inflationrate;
	double currentIncome;
	double incomeNeedFRetire;
	double PresentValueBalance;
	
	
	cout<<"\n=====Retirement Calculator=====\n";
	cout<<"Enter your current age: ";
	cin>>age;
	cout<<"Enter your planned retirement age: ";
	cin>>retireAge;
	int totalYear =retireAge-age;
	cout<<"Enter your life expectancy: ";
	cin>>lifeExpectancy;
	cout<<"Enter your current savings ($): ";
	cin>>currentSavings;
	cout<<"Enter your annual retirement contribution ($) ";
	cin>>AnnualRetireContribu;
	cout<<"Enter your expected annual return rate (as %) ";
	cin>>annualReturnRate;
	cout<<"Enter the inflation rate (as %): ";
	cin>>inflationrate;
	cout<<"Enter your current income ($): ";
	cin>>currentIncome;
	cout<<"Enter the income needed per year after retirement (in today's dollars) ($): ";
	cin>>incomeNeedFRetire;
	cout<<"\n=====Retirement Summary=====\n";
	cout<<"Years to retirement: "<<totalYear<<'\n';
	
	//futureSaving formula//
	double futureSavings = currentSavings;
	for(int i=0;i<totalYear;i++){
		futureSavings=(futureSavings*(1+(annualReturnRate/100)))+AnnualRetireContribu;
	}
	cout << fixed << setprecision(2);
	cout<<"Projected total savings at retirement: $"<<futureSavings<<'\n';	
	
	//Calculate Present Value Balance
	PresentValueBalance=futureSavings/(pow(1+inflationrate/100, totalYear));
	cout<<"Equivalent to current purchasing power: $"<<PresentValueBalance<<'\n';
	
	//Estimated amount John Tan needs at retirement age
	//Adjust income needed for inflation: 
	double adjustedIncomeNeed = incomeNeedFRetire * (pow(1 + inflationrate/100, totalYear));

	// Required amount at retirement:
	double requiredAmount = adjustedIncomeNeed * 25;
	cout<<"Estimated amount John Tan needs at retirement age: $"<<requiredAmount<<'\n';

	cout<<"\n===== Monthly Withdrawal Estimate =====\n";
	cout<<"After retirement (if saved $"<<futureSavings<<"): \n";
	
	//calculate monthly withdrawal (actual)
	double monthlyRate = (annualReturnRate/12)/100;
	int monthsRetired = (lifeExpectancy - retireAge) * 12;
	double monthlyWithdrawal = (futureSavings*monthlyRate)/(1 - pow(1+monthlyRate,-monthsRetired));
	cout<<"Actual amount income: $"<<monthlyWithdrawal<<" / month"<<'\n';

	double todaysMoney = monthlyWithdrawal/(pow(1+inflationrate/100, totalYear));
	cout<<"Today's money: $"<<todaysMoney<<" / month"<<'\n';

	cout<<"\n===== Fixed Purchasing Power Withdrawal =====\n";
	
	double realReturn = ((1+annualReturnRate/100)/(1+inflationrate/100))-1;
	double realMonthlyRate = realReturn/12;
	double fixedPurchasingWithdrawal = (futureSavings * realMonthlyRate)/(1-pow(1+realMonthlyRate, -monthsRetired));
	cout<<"Monthly withdrawal at 65, increasing 3.50% annually: $"<<fixedPurchasingWithdrawal<<'\n';

	double fixedPurchasingWithdrawalToday =fixedPurchasingWithdrawal/(pow(1+inflationrate/100, totalYear));
	cout<<"Equivalent to current purchase power of: $"<<fixedPurchasingWithdrawalToday<<'\n';

	cout<<"\n===== Conclusion =====\n";
	cout<<">>> John Tan is on track for retirement! \n";
	
	
	
	system("pause");

	return 0;
}
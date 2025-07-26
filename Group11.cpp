#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


void clearInput() {
    cin.clear();
    cin.ignore(10000, '\n');
}

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
	
	cout << "\n=====Retirement Calculator=====\n";

    while (true) {
        cout << "Enter your current age: ";
        if (cin >> age && age >= 0) break;
        cout << "Invalid input, your age should be a non-negative number.\n";
        clearInput();
    }

    while (true) {
        cout << "Enter your planned retirement age: ";
        if (cin >> retireAge && retireAge > age) break;
        cout << "Retirement age should be greater than current age.\n";
        clearInput();
    }

    int totalYear = retireAge - age;

    while (true) {
        cout << "Enter your life expectancy: ";
        if (cin >> lifeExpectancy && lifeExpectancy > retireAge) break;
        cout << "Life expectancy should be greater than retirement age.\n";
        clearInput();
    }

    while (true) {
        cout << "Enter your current savings ($): ";
        if (cin >> currentSavings && currentSavings >= 0) break;
        cout << "Invalid input, must be non-negative.\n";
        clearInput();
    }

    while (true) {
        cout << "Enter your annual retirement contribution ($): ";
        if (cin >> AnnualRetireContribu && AnnualRetireContribu >= 0) break;
        cout << "Invalid input, must be non-negative.\n";
        clearInput();
    }

    while (true) {
        cout << "Enter your expected annual return rate (as %): ";
        if (cin >> annualReturnRate && annualReturnRate >= 0) break;
        cout << "Invalid input, must be non-negative.\n";
        clearInput();
    }

    while (true) {
        cout << "Enter the inflation rate (as %): ";
        if (cin >> inflationrate && inflationrate >= 0) break;
        cout << "Invalid input, must be non-negative.\n";
        clearInput();
    }

    while (true) {
        cout << "Enter your current income ($): ";
        if (cin >> currentIncome && currentIncome >= 0) break;
        cout << "Invalid input, must be non-negative.\n";
        clearInput();
    }

    while (true) {
        cout << "Enter the income needed per year after retirement (in today's dollars) ($): ";
        if (cin >> incomeNeedFRetire && incomeNeedFRetire >= 0) break;
        cout << "Invalid input, must be non-negative.\n";
        clearInput();
    }
	
	cout<<"\n=====Retirement Summary=====\n";
	cout<<"Years to retirement: "<<totalYear<<" years"<<'\n';
	
	//futureSaving formula
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
	double monthlyRate = annualReturnRate/12/100;
	int monthsRetired = (lifeExpectancy - retireAge) * 12;
	double monthlyWithdrawal = (futureSavings*monthlyRate)/(1 - pow(1+monthlyRate,-monthsRetired));
	cout<<"Actual amount income: $"<<monthlyWithdrawal<<" / month"<<'\n';

	double todaysMoney = monthlyWithdrawal/(pow(1+inflationrate/100, totalYear));
	cout<<"Today's money: $"<<todaysMoney<<" / month"<<'\n';

	cout<<"\n===== Fixed Purchasing Power Withdrawal =====\n";
	
	double realReturn = ((1+annualReturnRate/100)/(1+inflationrate/100))-1;
	double realMonthlyRate = realReturn/12;
	double fixedPurchasingWithdrawal = (futureSavings * realMonthlyRate)/(1-pow(1+realMonthlyRate, -monthsRetired));
	cout<<"Monthly withdrawal at "<<retireAge<<", increasing "<<inflationrate << "annually: $"<<fixedPurchasingWithdrawal<<'\n';

	double fixedPurchasingWithdrawalToday =fixedPurchasingWithdrawal/(pow(1+inflationrate/100, totalYear));
	cout<<"Equivalent to current purchase power of: $"<<fixedPurchasingWithdrawalToday<<'\n';

	cout<<"\n===== Conclusion =====\n";
	cout<<">>> John Tan is on track for retirement! \n\n";
	
	//Part F: Enhancement
    cout<<"The amount you have: $"<<static_cast<int>(futureSavings)<<'\n';
    cout<<"You plan to withdraw: $"<<static_cast<int>(fixedPurchasingWithdrawal)<<" / month\n";
    cout<<"Average investment return: "<<static_cast<int>(annualReturnRate)<<'%'<<'\n';
	cout<<"\nResult:\n";
    
    double months = log(fixedPurchasingWithdrawal / (fixedPurchasingWithdrawal - futureSavings * annualReturnRate/12/100))
                     / log(1 + annualReturnRate/12/100);

    int years = static_cast<int>(months) / 12;
    double remainingMonths = fmod(months, 12);

    cout << "If withdraw $" << static_cast<int>(fixedPurchasingWithdrawal) << " per month, $" << static_cast<int>(futureSavings) 
         << " can last " << years << " years and " <<fixed << setprecision(1)<< remainingMonths << " months.\n";


	return 0;
}
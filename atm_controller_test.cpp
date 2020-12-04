#include <unordered_set>

#include "atm_controller.h"

using namespace std;

void TestAtmController() {
	int account_num = 3344786;
	int pin = 9999;
	string user = "User";
	unordered_map<string, int> account_info;
	account_info["checking"] = 1000;
	UserInfo user_info(account_num, pin, user, account_info);
	AtmController atm_controller;
	// Assume we can query the user info from the database
	atm_controller.QueryUserInfo();
	if (!atm_controller.CheckValidPin(9999)) {
		cout << "CheckValidPin error" << endl;
		return;
	}
	if (atm_controller.GetAllAccounts().empty()) {
		cout << "GetAllAccounts error" << endl;
		return;
	}
	if (!atm_controller.SelectAccount("checking")) {
		cout << "SelectAccount error" << endl;
		return;
	}
	if (atm_controller.GetAccountBalance() != 1000) {
		cout << "GetAccountBalance error" << endl;
		return;
	}
	if (!atm_controller.Withdraw(999)) {
		cout << "Withdraw error" << endl;
		return;
	}
	cout << "Pass all atm controller test" << endl;
}

int main() {
	TestAtmController();
	return 0;
}

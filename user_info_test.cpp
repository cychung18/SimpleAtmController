#include "user_info.h"

using namespace std;

void TestUserInfo() {
	int account_num = 3344786;
	int pin = 9999;
	string user = "User";
	unordered_map<string, int> account_info;
	account_info["checking"] = 1000;
	UserInfo user_info(account_num, pin, user, account_info);
	if (user_info.account_num() != account_num) {
		cout << "wrong acount num setup" << endl;
		return;
	}
	if (user_info.user_name() != user) {
		cout << "wrong user name setup" << endl;
		return;
	}
	auto accounts = user_info.GetAllAcounts();
	if (accounts[0] != "checking") {
		cout << "wrong account setup" << endl;
		return;
	}
	int balance = user_info.GetAccountBalance();
	if (balance != 1000) {
		return;
		cout << "wrong balance setup" << endl;
	}
	cout << "Pass all user info test" << endl;
}

int main() {
	TestUserInfo();
	return 0;
}

#include "user_info.h"

using namespace std;

class AtmController {
 public:
 	bool QueryUserInfo(string account_num);
 	bool CheckValidPin(string pin);
 	vector<string> GetAllAccounts();
 	bool SelectAccount(string account);
 	bool GetAccountBalance();
 	bool Deposit(int dollars);
 	bool Withdraw(int dollars);
 	bool FinishAllOperation();
 private:
 	bool is_user_info_initialized_ = false;
 	UserInfo user_info_;
 	string selected_account_;
};
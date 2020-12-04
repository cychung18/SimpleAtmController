#include<map>
#include<string>
#include<vector>

using namespace std;

class UserInfo {
 public:
 	int account_num() {
 		return account_num_;
 	}
 	string pin_num() {
 		return pin_number_;
 	}
 	string user_name() {
 		return user_name_;
 	}
 	vector<string> GetAllAcounts();
 	int GetAccountBalance(string account);
 	void DepositOrWithdraw(string account, int dollars);

 private:
 	int account_num_;
 	string pin_num_;
 	string user_name_;
 	map<string, int> account_info_;
};

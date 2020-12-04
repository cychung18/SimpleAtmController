#include "user_info.h"

vector<string> UserInfo::GetAllAcounts() {
	vector<string> accounts;
	accounts.reserve(account_info_.size()):
	for (const auto& pair : account_info_) {
		accounts.push_back(pair.first);
	}
	return accounts;
}

int UserInfo::GetAccountBalance(string account) {
	if (!account_info_.count(account)) {
		LOG("Invalid account name: " + account);
		return -1;
	}
	return account_info_.at(account);
}

void UserInfo::DepositOrWithdraw(string account, int dollars) {
	if (!account_info_.count(account)) {
		LOG("Invalid account name: " + account);
		return;
	}
	account_info_[account] += dollars;
}

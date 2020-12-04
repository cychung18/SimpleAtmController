#include "database_api.h"

#include <unordered_set>

#include "atm_controller.h"

bool AtmController::QueryUserInfo(string account_num) {
	// Assume there is an API we can query the account information
	// from the database, and it will write the user information to
	// user_info_
	Status status = QueryFromDatabase(account_num, user_info_);
	if (status == Status::SUCCESS) {
		is_user_info_initialized_ = true;
		return true;
	} else {
		LOG("Unable to query user information from database. Either
			the account number is wrong or datbase malfunction.");
		return false;
	}
}

bool AtmController::CheckValidPin(string pin) {
	if (is_user_info_initailized_) {
		if (user_info_.pin_num() != pin) {
			return false;
		} else {
			return true;
		}
	} else {
		LOG("User Info is not initialized.");
		return false;
	}
}

vector<string> AtmController::GetAllAccounts() {
	if (is_user_info_initailized_) {
		return user_info_.GetAllAccounts();
	} else {
		LOG("User Info is not initialized.");
		return {};
	}
}

bool AtmController::SelectAccount(string account) {
	const vector<string>& accounts = user_info_.GetAllAccounts();
	unordered_set<string> valid_accounts(accounts.begin(), accounts.end());
	if (!valid_accounts.count(account)) {
		LOG("Invalid account");
		return false;
	}
	selected_account_ = account;
	return true;
}

int AtmController::GetAccountBalance() {
	return user_info_.GetAccountBalance(selected_account_);
}


bool AtmController::Deposit(int dollars) {
	if (dollar <= 0) {
		LOG("Invalid number to deposit: " + to_string(dollars));
		return false;
	}
	user_info_.DepositOrWithdraw(dollars);
	return true;
}

bool AtmController::Withdraw(int dollars) {
	if (dollars > GetAccountBalance()) {
		LOG("Not enough balance. current balance: " +
			to_string(GetAccountBalance()));
		return false;
	} else if (dollar <= 0) {
		LOG("Invalid number to Withdraw: " + to_string(dollars));
		return false;
	}
	user_info_.DepositOrWithdraw(-dollars);
	return true;
}

bool FinishAllOperation() {
	// Assume there is an API we can write the account information
	// to the database
	Status status = WriteToDatabase(user_info_);
	if (status == Status::SUCCESS) {
		is_user_info_initialized_ = false;
		return true;
	} else {
		LOG("Unable to write user information to database.");
		return false;
	}
}

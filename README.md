# SimpleAtmController

This is the simple atm controller. In this Api, I define user information including user_name, account number, pin number, balance, etc. In AtmController, I support several API:
- bool QueryUserInfo(string account_num);
-	bool CheckValidPin(string pin);
-	vector<string> GetAllAccounts();
- bool SelectAccount(string account);
-	bool GetAccountBalance();
-	bool Deposit(int dollars);
-	bool Withdraw(int dollars);
-	bool FinishAllOperation();

For frontend design, it can use it directly to implement `Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw`.
I also implemented unit-test for both UserInfo and AtmController. But I assume that it will get the user information from database API. Some part of the code is not runnable unless we replace the database API I assume.

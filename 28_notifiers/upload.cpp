class INotifier{
public:
	virtual void Notify(const string& message) const = 0;
};

class SmsNotifier : public INotifier{
public:
	SmsNotifier(const string& num){
		number = num;
	}
	void Notify (const string& message) const override {
		SendSms(number, message);
	}
private:
	string number;
};

class EmailNotifier : public INotifier{
public:
	EmailNotifier(const string& mail){
		email = mail;
	}
	void Notify (const string& message) const override {
		SendEmail(email, message);
	}
private:
	string email;
};

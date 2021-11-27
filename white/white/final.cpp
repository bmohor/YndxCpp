#include <map>
#include <set>
#include <iomanip>
#include <iostream>
#include <algorithm>

class Date {
	public:
		Date(int a, int b, int c) {
			year = a;
			month = b;
			day = c;
		}
		int GetYear() const {
			return year;
		}
		int GetMonth() const {
			return month;
		}
		int GetDay() const {
			return day;
		}
	private:
		int year;
		int month;
		int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() < rhs.GetYear())
		return (true);
	if (lhs.GetYear() > rhs.GetYear())
		return (false);
	if (lhs.GetMonth() < rhs.GetMonth())
		return (true);
	if (lhs.GetMonth() > rhs.GetMonth())
		return (false);
	if (lhs.GetDay() < rhs.GetDay())
		return (true);
	return (false);
}

class Database {
	public:
		void AddEvent(const Date& date, const std::string& event) {
			clndr[date].insert(event);
		}
		bool DeleteEvent(const Date& date, const std::string& event) {
			if (clndr.count(date) > 0) {
				auto res = std::find(begin(clndr[date]), end(clndr[date]), event);
				if (res != end(clndr[date])) {
					clndr[date].erase(event);
					if (clndr[date].size() == 0)
						clndr.erase(date);
					std::cout << "Deleted successfully" << std::endl;
					return 1;
				}
			}
			std::cout << "Event not found" << std::endl;
			return 0;
		}
		int  DeleteDate(const Date& date) {
			if (clndr.count(date) > 0) {
				int res = clndr[date].size();
				clndr.erase(date);
				return res;
			} else {
				return 0;
			}
		}
		bool Find(const Date& date) const {
			if (clndr.count(date) > 0) {
				std::set<std::string> tmp = clndr.at(date);
				for(const auto& i : tmp) {
					std::cout << i << std::endl;
				}
				return 1;
			}
			return 0;
		}
		void Print() const {
			for (const auto& i : clndr) {
				for (const auto& j : i.second) {
					std::cout.fill('0');
					std::cout << std::setw(4) << i.first.GetYear();
					std::cout << '-';
					std::cout << std::setw(2) << i.first.GetMonth();
					std::cout << '-';
					std::cout << std::setw(2) << i.first.GetDay();
					std::cout << ' ' << j;
					std::cout << std::endl;
				}
			}
		}
	private:
		std::map<Date, std::set<std::string>> clndr;
};

void	dataCheck(int (&nums)[3], int code) {
	int count = 0;
	std::string event, str;
	std::cin >> str;
	for (int i = 0; str[i] != '\0'; i++) {
		std::string num = "";
		int minus = 0;
		if (str[i] == '-' || str[i] == '+') {
			if (str[i] == '-')
				minus = 1;
			i++;
		}
		if (isdigit(str[i]) == 0)
			throw std::invalid_argument("Wrong date format: " + str);
		while (isdigit(str[i]) != 0 && str[i] != '\0') {
			num += str[i];
			i++;
		}
		nums[count] = std::stoi(num);
		if (minus == 1)
			nums[count] *= -1;
		count++;
		if (count == 3) {
			if (str.size() > i)
				throw std::invalid_argument("Wrong date format: " + str);
			break;
		}
		if (str[i] == '\0')
			break;
		if (str[i] != '-')
			throw std::invalid_argument("Wrong date format: " + str);
	}
	if (count != 3)
		throw std::invalid_argument("Wrong date format: " + str);
	if (std::cin.peek() != ' ') {
		if (std::cin.peek() != '\n')
			throw std::invalid_argument("Wrong date format: " + str);
	}
	if (nums[1] < 1 || nums[1] > 12) {
		getline(std::cin, event);
		throw std::invalid_argument("Month value is invalid: " + std::to_string(nums[1]));
	}
	if (nums[2] < 1 || nums[2] > 31) {
		getline(std::cin, event);
		throw std::invalid_argument("Day value is invalid: " + std::to_string(nums[2]));
	}
}	

void findMe(Database& db) {
	int nums[3];
	std::string event;
	dataCheck(nums, 2);
	Date date(nums[0], nums[1], nums[2]);
	db.Find(date);
}

void del(Database& db) {
	int nums[3];
	std::string event;
	dataCheck(nums, 1);
	Date date(nums[0], nums[1], nums[2]);
	if (std::cin.peek() == '\n') {
		int res = db.DeleteDate(date);
		std::cout << "Deleted " << res << " events" << std::endl;
	}
	else {
		std::cin >> event;
		db.DeleteEvent(date, event);
	}
}

void add(Database& db) {
	int nums[3];
	std::string event;
	dataCheck(nums, 0);
	Date date(nums[0], nums[1], nums[2]);
	std::cin >> event;
	db.AddEvent(date, event);
}

int main() {
	Database db;
	
	std::string command;
	while (std::cin >> command) {
		try {
			if (command == "\0")
				continue;
			else if (command == "Add")
				add(db);
			else if (command == "Del")
				del(db);
			else if (command == "Find")
				findMe(db);
			else if (command == "Print")
				db.Print();
			else
				throw std::invalid_argument("Unknown command: " + command);
		} catch(const std::invalid_argument& ex) {
			std::cout << ex.what() << std::endl;
			return 0;
		}
	}
	return 0;
}

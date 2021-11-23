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
				if (res == std::end(clndr[date])) {
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
				std::cout.fill('0');
				std::cout << std::setw(4) << i.first.GetYear();
				std::cout << '-';
				std::cout << std::setw(2) << i.first.GetMonth();
				std::cout << '-';
				std::cout << std::setw(2) << i.first.GetDay();
				for (const auto& j : i.second)
					std::cout << ' ' << j;
				std::cout << std::endl;
			}
		}
	private:
		std::map<Date, std::set<std::string>> clndr;
};

void	dataCheck(int& a, int& b, int& c, int code) {
	char x, z;
	std::string event;
	std::cin >> a >> x >> b >> z >> c;
	if (code == 1 && (std::cin.peek() != ' ' || x != '-' || z != '-')) {
		if (std::cin.peek() != '\n' || x != '-' || z != '-') {
			std::string tmp;
			std::string t = "";	
			if (std::cin.peek() != ' ') {
				if (std::cin.peek() != '\n')
					std::cin >> t;
			}
			tmp = std::to_string(a) + x + std::to_string(b) + z + std::to_string(c) + t;
			getline(std::cin, event);
			throw std::invalid_argument("Wrong date format: " + tmp);
		}
	} else if (std::cin.peek() != ' ' || x != '-' || z != '-') {
		std::string tmp;
		std::string t = "";	
		if (std::cin.peek() != ' ') {
			if (std::cin.peek() != '\n')
				std::cin >> t;
		}
		tmp = std::to_string(a) + x + std::to_string(b) + z + std::to_string(c) + t;
		getline(std::cin, event);
		throw std::invalid_argument("Wrong date format: " + tmp);
	}
	if (b < 1 || b > 12) {
		getline(std::cin, event);
		throw std::invalid_argument("Month value is invalid: " + std::to_string(b));
	}
	if (c < 1 || c > 31) {
		getline(std::cin, event);
		throw std::invalid_argument("Day value is invalid: " + std::to_string(c));
	}
}	

void findMe(Database& db) {
	try {
		int a, b, c;
		std::string event;
		dataCheck(a, b, c, 1);
		Date date(a, b, c);
		db.Find(date);
	} catch(const std::invalid_argument& ex) {
		std::cout << ex.what() << std::endl;
	}

}

void del(Database& db) {
	try {
		int a, b, c;
		std::string event;
		dataCheck(a, b, c, 1);
		Date date(a, b, c);
		if (std::cin.peek() == '\n') {
			int res = db.DeleteDate(date);
			std::cout << "Deleted " << res << " events" << std::endl;
		}
		else {
			std::cin >> event;
			db.DeleteEvent(date, event);
		}
	} catch(const std::invalid_argument& ex) {
		std::cout << ex.what() << std::endl;
	}
}

void add(Database& db) {
	try {
		int a, b, c;
		std::string event;
		dataCheck(a, b, c, 0);
		Date date(a, b, c);
		std::cin >> event;
		db.AddEvent(date, event);
	} catch(const std::invalid_argument& ex) {
		std::cout << ex.what() << std::endl;
	}
}

int main() {
	Database db;
	
	std::string command;
	while (1) {
		std::cin >> command;
		if (command == "\0")
			continue;
		else if (command == "Add") {
			add(db);
		} else if (command == "Del") {
			del(db);
		} else if (command == "Find") {
			findMe(db);
		} else if (command == "Print") {
			db.Print();
		} else {
			std::cout << "Unknown command: " + command << std::endl;
		}
	}
	return 0;
}

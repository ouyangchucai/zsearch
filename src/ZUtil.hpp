
/**
 * Since we're not using boost, this utility class is to help us get some basic stuff done :)
 */

#ifndef ZUTIL_HPP
#define ZUTIL_HPP

#include <string>
#include <sstream>
#include <chrono>

using namespace std;


class ZUtil
{
	public:

		static int getInt(const std::string& str)
		{
			int x;
			stringstream ss(str);
			ss >> x;

			if (!ss)
			{
				string msg = "Provided string is not an integer : " + str;
				throw msg;
			}

			return x;
		}

		static unsigned int getUInt(const std::string& str)
		{
			unsigned int x;
			stringstream ss(str);
			ss >> x;

			if (!ss)
			{
				string msg = "Provided string is not an unsigned integer : " + str;
				throw msg;
			}

			return x;
		}

		static string getString(int number)
		{
		   stringstream ss;
		   ss << number;
		   return ss.str();
		}

		static string printTimeTaken(const std::chrono::nanoseconds& ns)
		{
			stringstream ss;

			if (ns.count() >= 1000000000)
			{
				ss << "function returned in " << std::chrono::duration_cast<std::chrono::seconds>(ns).count() << "s";
			}
			else if (ns.count() >= 1000000)
			{
				ss << "function returned in " << std::chrono::duration_cast<std::chrono::milliseconds>(ns).count() << "ms";
			}
			else
			{
				ss << "function returned in " << ns.count() << "ns";
			}

			return ss.str();
		}


};

#endif
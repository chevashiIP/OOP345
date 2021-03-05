#ifndef _NOTIFICATIONS_H_
#define _NOTIFICATIONS_H_

#include <iostream>
#include <fstream>

#include "Message.h"

namespace sict {
	class Notifications {
		int mescount;
		Message* tweets;
	public:
		Notifications(std::ifstream&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();
		void display(std::ostream& os) const;
	};
}


#endif // !_NOTIFICATIONS_H_


/* 
 * File:   OculusPrimeInterface.h
 * Author: eugene
 * Copyright (c) 2015 Eugene Gilmore                                       
 * All rights reserved. 
 *
 * Created on 28 July 2015, 6:53 PM
 */

#ifndef OCULUSPRIMEINTERFACE_H
#define	OCULUSPRIMEINTERFACE_H

#include <wb_oculus_prime_interface.h>

namespace guWhiteboard {

	class OculusPrimeInterface : public wb_oculus_prime_interface {
	public:
		OculusPrimeInterface() : wb_oculus_prime_interface() {
		}
		
		OculusPrimeInterface(const std::string &str) {
			from_string(str);
		}
		
		void from_string(const std::string &/*str*/) {
			//TODO
		}
	};

}

#endif	/* OCULUSPRIMEINTERFACE_H */


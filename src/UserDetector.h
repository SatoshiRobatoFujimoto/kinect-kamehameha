//@COPYRIGHT@//
//
// Copyright (c) 2011, Tomoto S. Washio
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//   * Neither the name of the Tomoto S. Washio nor the names of his
//     contributors may be used to endorse or promote products derived from
//     this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL TOMOTO S. WASHIO BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//@COPYRIGHT@//

#ifndef _USER_DETECTOR_H_
#define _USER_DETECTOR_H_

#include "common.h"
#include "vec.h"
#include "IUserListener.h"
#include "UserProvider.h"

class UserDetector
{
private:
	UserProvider* m_userProvider;
	IUserListener* m_listener;

	XuUserID m_trackedUserID;

	XuSkeletonJointInfo m_jointInfos[XU_SKEL_JOINT_COUNT];

public:
	UserDetector(UserProvider* userProvider);
	~UserDetector();

	void detect();

	XuUserID getTrackedUserID()
	{
		return m_trackedUserID;
	}

	bool isTrackedUserID(XuUserID userID)
	{
		return getTrackedUserID() == userID;
	}

	bool isSkeletonTracked()
	{
		return m_trackedUserID && m_userProvider->isUserSkeletonTracked(m_trackedUserID);
	}

	void switchUser();

	void addListener(IUserListener* listener);

	XV3 getSkeletonJointPosition(XuSkeletonJointIndex jointID);
	void getSkeletonJointInfo(XuSkeletonJointIndex eJoint, XuSkeletonJointInfo* pJointInfo);

	XV3 getForwardVector(); // returns the vector to the direction from the back to the front
	XV3 getUpVector(); // returns the vector to the body to the head
};

#endif

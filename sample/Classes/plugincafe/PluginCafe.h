/*
 * PluginCafe.h
 *
 *  Created on: 2016. 3. 22.
 *      Author: naver
 */

#ifndef JNI_PLUGINCAFE_PLUGINCAFE_H_
#define JNI_PLUGINCAFE_PLUGINCAFE_H_

#include <string>

namespace cafe {

class CafeListener {
public:
    virtual void onCafeSdkStarted() = 0;
    virtual void onCafeSdkStopped() = 0;
    virtual void onCafeSdkClickAppSchemeBanner(
            const std::string& appScheme) = 0;
    virtual void onCafeSdkJoined() = 0;
    virtual void onCafeSdkPostedArticle(int menuId) = 0;
    virtual void onCafeSdkPostedComment(int articleId) = 0;
    virtual ~CafeListener();
};

class CafeSdk {
public:
    /* 네아로 정보와 카페 아이디로 sdk 초기화 합니다. */
    static void init(std::string clientId, std::string clientSecret,
            int cafeId);

    static void setCafeListener(CafeListener* listener);

    static void startHome();
    static void startNotice();
    static void startEvent();
    static void startMenu();
    static void startMenu(int menuId);
    static void startProfile();
    static void startMore();

    static void startWrite(int menuId, std::string subject, std::string text);
    static void startImageWrite(int menuId, std::string subject,
            std::string text, std::string imageUri);
    static void startVideoWrite(int menuId, std::string subject,
            std::string text, std::string videoUri);

    /* 게임 아이디와 카페 아이디를 연동합니다. */
    static void syncGameUserId(std::string gameUserId);

    static void showToast(std::string text);
};

} /* namespace cafe */

#endif /* JNI_PLUGINCAFE_PLUGINCAFE_H_ */
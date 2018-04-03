#ifndef HTTPOP_H
#define HTTPOP_H

#include <QtNetwork\QNetworkAccessManager>
#include <QtNetwork\QNetworkRequest>
#include <QtNetwork\QNetworkReply>
#include <QTimer>
#include <QtNetwork\QSslConfiguration>
#include <QString>
#include <QByteArray>

#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

extern QString token;//定义在login_dialog.h里

class HttpOp : public QObject
{
    Q_OBJECT
public:
    explicit HttpOp(QObject *parent = 0);
    QString reBaseUrl();
    void getRequest(const QString& strUrl, QString op);//根据url发起http请求
	void postRequest(const QString& strUrl, QByteArray post_data);
    QString OPmode;//GET,POST,HEAD,PUT...


signals:
    void signal_requestFinished(bool bSuccess, QNetworkReply& reply); //http请求结束
public slots:
    void slot_requestFinished(); //http请求结束
    void slot_requestTimeout();  //请求超时

private:
    const QString BaseUrl = "https://www.easy-mock.com/mock/5ab77f6d89962b05a31a3166/api";//for mocking
    QNetworkAccessManager* m_pNetworkManager;//网络管理对象
    QNetworkReply* m_pNetworkReply; //封装请求返回信息
    QTimer* m_pTimer; //请求超时计时器
    QString m_strUrl; //记录当前请求的url
};



#endif // HTTPOP_H

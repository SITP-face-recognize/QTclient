#include <httpop.h>

#include <QTextCodec>

const int nHTTP_TIME = 10000; //10秒

HttpOp::HttpOp(QObject *parent) :
    QObject(parent)
{
    m_pNetworkManager = new QNetworkAccessManager(this);
    m_pNetworkReply = NULL;
    m_pTimer = new QTimer;
    connect(m_pTimer,SIGNAL(timeout()),this,SLOT(slot_requestTimeout()));//超时信号
}

QString HttpOp::reBaseUrl()
{
    return BaseUrl;
}

void HttpOp::getRequest(const QString &strUrl, QString op)
{
    m_strUrl = strUrl;
    QNetworkRequest netRequest;
    netRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");	
    netRequest.setUrl(QUrl(strUrl)); //地址信息

    m_pNetworkReply = m_pNetworkManager->get(netRequest); //发起get请求
    
    connect(m_pNetworkReply,SIGNAL(finished()),this,SLOT(slot_requestFinished())); //请求完成信号
    m_pTimer->start(nHTTP_TIME);
}

void HttpOp::postRequest(const QString & strUrl, QByteArray post_data)
{
	m_strUrl = strUrl;
	QNetworkRequest netRequest;
	netRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	//netRequest.setRawHeader(QByteArray("Authorition: Token "), token.toUtf8());//token

	netRequest.setHeader(QNetworkRequest::ContentLengthHeader, post_data.length());
	netRequest.setUrl(QUrl(strUrl)); //地址信息

	m_pNetworkReply = m_pNetworkManager->post(netRequest, post_data);
	connect(m_pNetworkReply, SIGNAL(finished()), this, SLOT(slot_requestFinished())); //请求完成信号
	m_pTimer->start(nHTTP_TIME);
}

//请求结束
void HttpOp::slot_requestFinished()
{
    m_pTimer->stop();//关闭定时器
    int nHttpCode = m_pNetworkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();//http返回码
    qDebug() << "HttpCode" <<nHttpCode;
	if(nHttpCode == 200)//成功     
        emit signal_requestFinished(true,*m_pNetworkReply);//请求成功
    else
        emit signal_requestFinished(false,*m_pNetworkReply);//请求失败
    
    m_pNetworkReply->deleteLater();
    this->deleteLater(); //释放内存
}

//请求超时
void HttpOp::slot_requestTimeout()
{
    emit signal_requestFinished(false,*m_pNetworkReply);//请求失败
    m_pNetworkReply->deleteLater();
    this->deleteLater();//释放内存
}

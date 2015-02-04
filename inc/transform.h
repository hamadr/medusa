#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QProcess>

class Transform : public QObject {
    Q_OBJECT

public:
    Transform();
    ~Transform();
    bool transform(QString path, QString &code);
private slots:
    void pythonFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void readStandardError();
    void readStandardOutput();
    void shitHappened(QProcess::ProcessError);
private:
    QSqlDatabase db;
    QProcess *python;
    QString path, reply;
    int exitCode;
};

#endif

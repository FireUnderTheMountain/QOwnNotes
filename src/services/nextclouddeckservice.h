#ifndef QOWNNOTES_NEXTCLOUDDECKSERVICE_H
#define QOWNNOTES_NEXTCLOUDDECKSERVICE_H

#include <QDateTime>
#include <QObject>
#include <QtNetwork/QNetworkRequest>

#include "entities/cloudconnection.h"

class NextcloudDeckService : public QObject {
    Q_OBJECT

    struct Board {
        int id;
        QString title;
        QHash<int, QString> stacks;

        bool hasStacks() {
            return !stacks.isEmpty();
        }

//        QDebug operator<<(QDebug dbg, const Board & board) {
//            dbg.nospace() << "Bookmark: <title>" << board.title << " <id>" << board.id << " <stacks>"
//                          << board.stacks;
//            return dbg.space();
//        }
    };

   public:
    explicit NextcloudDeckService(QObject* parent, int cloudConnectionId = -1);
    int createCard(const QString& title, const QString& description = "", QDateTime* dueDateTime = nullptr);
    QString getCardLinkForId(int cardId);
    bool isEnabledAndValid();
    bool isEnabled();
    QList<Board> getBoards();

   private:
    CloudConnection cloudConnection;
    QString serverUrl;
    int boardId;
    int stackId;
    void addAuthHeader(QNetworkRequest& networkRequest);
};

#endif    // QOWNNOTES_NEXTCLOUDDECKSERVICE_H

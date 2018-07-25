#ifndef YASCOMPLETER_H
#define YASCOMPLETER_H

#include <QCompleter>

//Переведите кодировку в UTF-8



class YAScompleter: public QCompleter{
    Q_OBJECT
public:

    YAScompleter (QObject *p=0): QCompleter(p){
        QObject::connect(this, QOverload<const QModelIndex &>::of(&QCompleter::activated), this, YAScompleter::catching_index);
    }

    YAScompleter(QAbstractItemModel *model, QObject *p=0): QCompleter(model, p){
        QObject::connect(this, QOverload<const QModelIndex &>::of(&QCompleter::activated), this, YAScompleter::catching_index);
    }

    YAScompleter(const QStringList& strings, QObject *p=0): QCompleter(strings, p){
        QObject::connect(this, QOverload<const QModelIndex &>::of(&QCompleter::activated), this, YAScompleter::catching_index);
    }

    ~YAScompleter(){

    }

signals:
    void sendNaturalIndex(int);

private slots:
    void catching_index(const QModelIndex& index){
        QAbstractItemModel * const baseModel = model();
        QModelIndexList indexList = baseModel->match(
                    baseModel->index(0,completionColumn(),QModelIndex()),
                    completionRole(),
                    index.data(),
                    1,
                    Qt::MatchContains);
        if(!indexList.isEmpty()){
            emit sendNaturalIndex(indexList.at(0).row());
        }
    }
};





#endif // YASCOMPLETER_H

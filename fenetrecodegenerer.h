#ifndef FENETRECODEGENERER_H
#define FENETRECODEGENERER_H

#include <QObject>
#include <QWidget>
#include<QDialog>
#include<QTextEdit>
#include<QPushButton>
#include<QVBoxLayout>

class FenetreCodeGenerer : public QDialog
{
    Q_OBJECT
public :
    FenetreCodeGenerer(QString recuNom, QString recuClasseMere,
                       QString recuHeaderTopOpt,QString recuHeaderDownOpt,
                       QString recuConstructeurOptionOn, QString recuDestruOn,QString recuCommentaireOptionOn);

   static void startFenetreGenerer(QString recuNom, QString recuClasseMere, QString recuHeaderTopOpt,
                                   QString recuHeaderDownOpt, QString recuConstructeurOptionOn, QString recuDestruOn,QString recuCommentaireOptionOn);


private:
QBoxLayout *m_mainLayoutCode;
    QWidget *m_FenetreCodeGenerer;
        QVBoxLayout *m_codeGenererLayout;
            QTextEdit *m_resultatGenererTE;
            QPushButton *m_boutonFermerCodeGenerer;

    QString *receptionDesOptionString;
};

#endif // FENETRECODEGENERER_H

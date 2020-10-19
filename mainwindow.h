#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include<QtWidgets>
#include<QCheckBox>




class MainFenetre : public QWidget
{
    Q_OBJECT

public:
    MainFenetre();
public slots:
    void lancerFenetreGenerer();

private:
//Structure principal de la fenetre de réglage
    QWidget *fenetrePrincipal;
    QVBoxLayout *mainStrucLayout;

//definition de classe
    QGroupBox *m_definitionClasseGB;
        QGridLayout *m_grilleLayoutDefinitionClass;
            QLabel *nomDCLabel;    
            QLabel *classeMereDCLabel;

            QLineEdit *nomLE;
            QLineEdit *classeMereLE;
//Fin - definition de la classe

//option
    QGroupBox *m_definitionOptionGB;
        QVBoxLayout *m_optionLayout;
            QCheckBox *m_optionCBprotect;
            QCheckBox *m_optionCBConstru;
            QCheckBox *m_optionCBDestru;

//fin - option

//Ajout commentaire
    QGroupBox *m_commentaireGB;
        QGridLayout *m_commentaireLayout;
            QLabel *m_auteurLabel;
            QLabel *m_dateCreaLabel;
            QLabel *m_roleDeClasseLabel;

            QLineEdit *m_auteurLE;
            QDateEdit *m_dateCreaLE;

            QTextEdit *m_roleDeClasseTE;

//fin - Ajout commentaire
// Bouton Générer et quitter
    QHBoxLayout *m_genererQuitterLayout;
    QPushButton *m_boutonGenerer;
    QPushButton *m_boutonQuitter;


};
#endif // MAINWINDOW_H

#include "fenetrecodegenerer.h"


FenetreCodeGenerer::FenetreCodeGenerer(QString recuNom, QString recuClasseMere,
                                       QString recuHeaderTopOpt, QString recuHeaderDownOpt,
                                       QString recuConstructeurOptionOn, QString recuDestruOn,QString recuCommentaireOptionOn) : QDialog()
{
m_mainLayoutCode = new QVBoxLayout(this);
    m_FenetreCodeGenerer = new QWidget(this);

        m_codeGenererLayout = new QVBoxLayout(m_FenetreCodeGenerer);

            m_resultatGenererTE = new QTextEdit("test",this);
//Taille, police, readonly et selection sur code générer
                m_resultatGenererTE->setReadOnly(true);
                m_resultatGenererTE->setFont(QStringLiteral("Courier"));
                m_resultatGenererTE->selectAll();
                m_resultatGenererTE->setFontPointSize(10);




            m_boutonFermerCodeGenerer = new QPushButton("Fermer", this);

                QObject::connect(m_boutonFermerCodeGenerer, SIGNAL(clicked()), this, SLOT(close()));

            m_codeGenererLayout->addWidget(m_resultatGenererTE);
            m_codeGenererLayout->addWidget(m_boutonFermerCodeGenerer);


    m_FenetreCodeGenerer->setLayout(m_codeGenererLayout);
    m_mainLayoutCode->addWidget(m_FenetreCodeGenerer);

    //Reception des champ remplie pour le code générer
// réglage de lordre et affichage du txt ici
    receptionDesOptionString = new QString;

        if (recuClasseMere != ""){ recuClasseMere = (QString("public "+recuClasseMere));};

    m_resultatGenererTE->setText(recuCommentaireOptionOn+recuHeaderTopOpt+"class "+recuNom+" : "+recuClasseMere+'\n'
                                 +"{ \n\tpublic:\n\t\t"+recuConstructeurOptionOn+recuDestruOn+
                                 "\n\n\tprotected:\n\n\n\tprivate:\n\n"

                                 +"\n}\n\n"+recuHeaderDownOpt);

}



void FenetreCodeGenerer::startFenetreGenerer(QString recuNom, QString recuClasseMere,
                                             QString recuHeaderTopOpt,QString recuHeaderDownOpt,
                                             QString recuConstructeurOptionOn, QString recuDestruOn,QString recuCommentaireOptionOn)
{
    FenetreCodeGenerer laFenetreCode{recuNom, recuClasseMere,recuHeaderTopOpt,recuHeaderDownOpt,recuConstructeurOptionOn,recuDestruOn,recuCommentaireOptionOn};
        laFenetreCode.resize(600,800);
        laFenetreCode.setWindowIcon(QIcon("icone.png"));

    laFenetreCode.exec();//exec car modal alors que le show se ferme instant
}

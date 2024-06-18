QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accueil_gerant.cpp \
    afficher_facture.cpp \
    affichervente.cpp \
    ajouter_fournisseur.cpp \
    ajouter_stock_med.cpp \
    ajouter_utilisateurs.cpp \
    ajouter_vente_by_gerant.cpp \
    ajoutervente.cpp \
    consulter_stock.cpp \
    employee.cpp \
    gerer_stock.cpp \
    gestion_fournisseur.cpp \
    gestion_utilisateurs.cpp \
    gestion_ventes.cpp \
    main.cpp \
    mainwindow.cpp \
    modifier_fournisseur.cpp \
    modifier_profil_gerant.cpp \
    modifier_stock_med.cpp \
    modifier_utilisateurs.cpp \
    profil.cpp \
    profil_gerant.cpp \
    profil_modifie.cpp \
    recherchermed_emp.cpp \
    supprimer_fournisseur.cpp \
    supprimer_utilisateurs.cpp

HEADERS += \
    accueil_gerant.h \
    afficher_facture.h \
    affichervente.h \
    ajouter_fournisseur.h \
    ajouter_stock_med.h \
    ajouter_utilisateurs.h \
    ajouter_vente_by_gerant.h \
    ajoutervente.h \
    consulter_stock.h \
    employee.h \
    gerer_stock.h \
    gestion_fournisseur.h \
    gestion_utilisateurs.h \
    gestion_ventes.h \
    mainwindow.h \
    modifier_fournisseur.h \
    modifier_profil_gerant.h \
    modifier_stock_med.h \
    modifier_utilisateurs.h \
    profil.h \
    profil_gerant.h \
    profil_modifie.h \
    recherchermed_emp.h \
    supprimer_fournisseur.h \
    supprimer_utilisateurs.h

FORMS += \
    accueil_gerant.ui \
    afficher_facture.ui \
    affichervente.ui \
    ajouter_fournisseur.ui \
    ajouter_stock_med.ui \
    ajouter_utilisateurs.ui \
    ajouter_vente_by_gerant.ui \
    ajoutervente.ui \
    consulter_stock.ui \
    employee.ui \
    gerer_stock.ui \
    gestion_fournisseur.ui \
    gestion_utilisateurs.ui \
    gestion_ventes.ui \
    mainwindow.ui \
    modifier_fournisseur.ui \
    modifier_profil_gerant.ui \
    modifier_stock_med.ui \
    modifier_utilisateurs.ui \
    profil.ui \
    profil_gerant.ui \
    profil_modifie.ui \
    recherchermed_emp.ui \
    supprimer_fournisseur.ui \
    supprimer_utilisateurs.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc

DISTFILES += \
    OIP.jpeg

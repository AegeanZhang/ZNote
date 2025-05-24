#ifndef ABUT_DIALOG_H
#define ABUT_DIALOG_H

#include <QDialog>

class ZAboutDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ZAboutDialog(QWidget* parent = nullptr);
    ~ZAboutDialog();
    void setVersion(const QString& version);
    void setAuthor(const QString& author);
    void setLicense(const QString& license);
    void setDescription(const QString& description);
    void setLogo(const QString& logoPath);
    void setIcon(const QString& iconPath);
    void setWebsite(const QString& website);
    void setEmail(const QString& email);
    void setGithub(const QString& github);
};

#endif // ABUT_DIALOG_H
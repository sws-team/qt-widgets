#ifndef STYLES_H
#define STYLES_H

#include <QPalette>
#include <QMap>

namespace Arc {
	class Style
	{
	public:
		enum STYLE_TYPE
		{
			CLASSIC,
			DARK,

			USER_TYPE,
		};
		Style();

		STYLE_TYPE currentStyleType() const;
		void setStyle(STYLE_TYPE type);
		void addStyle(int type, const QPalette& palette);

		static const QString STYLE_NAME;
		static const QStringList STYLE_NAMES;
	private:
		STYLE_TYPE m_type;
		QMap<STYLE_TYPE, QPalette> styles;
		void fillStyles();
	};
} //end namespace Arc



#endif // STYLES_H

#pragma once

#include <iostream>
#include "../Config/Export.h"

//a inclure en dernier
#include "../DebugEngine/DebugNew.h"

namespace GameEngine
{
	/**
	 * Classe abstraite de serialisation
	 */
	class GAME_ENGINE_EXPORT ISerializable
	{
	public:
		/**
		 * Permet de charger un fichier de serialisation
		 * @param fileName_ nom du fichier � ouvrir
		 * @return true si le chargement � fini, sinon false
		 */
		bool LoadSerialized(const char* fileName_);

		/**
		 * Permet de sauvegarder un fichier de serialisation
		 * @param fileName_ nom du fichier � ouvrir
		 * @return true si le chargement � fini, sinon false
		 */
		bool SaveSerialized(const char* fileName_);

		/**
		 * @is flux d'entr�e
		 * @return le nombre d'octet lu
		 */
		virtual int Read(std::istream& is_) = 0;

		/**
		 * @os flux de sortie
		 * @return le meme flux modifi�
		 */
		virtual std::ostream& operator >> (std::ostream& os_) = 0;

		//virtual void ReadJson(std::istream& is_) = 0;
		//virtual void SaveJson(std::ostream& os_) = 0;
	};
} // namespace GameEngine


#include "../DebugEngine/DebugNewOff.h"

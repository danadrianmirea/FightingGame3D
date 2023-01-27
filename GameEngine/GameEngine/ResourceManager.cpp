//==========================================================
// Yes::Engine - Free C++ 3D engine
//
// Copyright (C) 2004-2005 Laurent Gomila
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc.,
// 59 Temple Place - Suite 330,
// Boston, MA  02111-1307, USA.
//
// E-mail : laurent.gom@gmail.com
//==========================================================


//==========================================================
// En-t�tes
//==========================================================
#include "ResourceManager.h"
#include "logger/Logger.h"
//#include <Debug/Exceptions.h>

//a inclure en dernier
#include "DebugEngine/DebugNew.h"


namespace GameEngine
{

////////////////////////////////////////////////////////////
// Impl�mentation des m�thodes du singleton
////////////////////////////////////////////////////////////
SINGLETON_IMPL(ResourceManager)


/////////////////////////////////////////////////////////////
/// Constructeur par d�faut
///
////////////////////////////////////////////////////////////
ResourceManager::ResourceManager()
{

}


/////////////////////////////////////////////////////////////
/// Destructeur
///
////////////////////////////////////////////////////////////
ResourceManager::~ResourceManager()
{
#ifdef _DEBUG
    // S'il reste des ressources dans la liste, on le signale
    if (!m_Resources.empty())
    {
        ILogger::Log() << "** warning ** Des ressources non pas �t� lib�r�es :\n";

        for (TResourcesMap::const_iterator i = m_Resources.begin(); i != m_Resources.end(); ++i)
        {
            ILogger::Log() << " - " << i->second->GetName() << "\n";
        }
    }
#endif // _DEBUG
}


/////////////////////////////////////////////////////////////
/// Ajoute une ressource
///
/// \param Name :     Nom associ� � la ressource
/// \param Resource : Pointeur sur la ressource � ajouter
///
////////////////////////////////////////////////////////////
void ResourceManager::Add(const std::string& Name, IResource* Resource)
{
    //Assert(Resource != NULL);
	if ( Resource == NULL )
		throw std::exception("ResourceManager::Add() : ressource null");

#ifdef _DEBUG
    // Si la ressource avait d�j� �t� charg�e, on le signale
    if (m_Resources.find(Name) != m_Resources.end())
		ILogger::Log() << "Ressource d�j� charg�e : " << Name << "\n";
#endif // _DEBUG

    // Ajout de la ressource � la liste
    m_Resources[Name] = Resource;
    Resource->m_Name = Name;
}


/////////////////////////////////////////////////////////////
/// Retire une ressource
///
/// \param Name : Nom de la ressource � retirer
///
////////////////////////////////////////////////////////////
void ResourceManager::Remove(const std::string& Name)
{
    // Recherche de la ressource dans la table
    TResourcesMap::iterator It = m_Resources.find(Name);

    // Si la ressource n'avait pas �t� charg�e, on le signale
    if (It == m_Resources.end())
	{
#ifdef _DEBUG
		ILogger::Log() << "Ressource inexistante : " << Name << " : impossible a supprimer !\n";
#endif
		return;
	}

    // Retrait de la ressource de la liste
    m_Resources.erase(It);
}

} // namespace GameEngine

#include "Resource.h"
#include "ResourceManager.h"

//a inclure en dernier
#include "DebugEngine/DebugNew.h"


namespace GameEngine
{

	/////////////////////////////////////////////////////////////
	/// Constructeur par d�faut
	///
	////////////////////////////////////////////////////////////
	IResource::IResource() :
		m_Name(""),
		m_RefCount(1)
	{

	}


	/////////////////////////////////////////////////////////////
	/// Destructeur
	///
	////////////////////////////////////////////////////////////
	IResource::~IResource()
	{
		if (!m_Name.empty())
		{
			ResourceManager::Instance().Remove(m_Name);
		}
	}


	/////////////////////////////////////////////////////////////
	/// Renvoie le nom associ� � la ressource
	///
	/// \return Nom attribu� � la ressource
	///
	////////////////////////////////////////////////////////////
	const std::string& IResource::GetName() const
	{
		return m_Name;
	}


	/////////////////////////////////////////////////////////////
	/// Ajoute une r�f�rence sur la ressource
	///
	////////////////////////////////////////////////////////////
	void IResource::AddRef()
	{
		++m_RefCount;
	}


	/////////////////////////////////////////////////////////////
	/// Retire une r�f�rence sur la ressource
	///
	/// \return Nombre de r�f�rences restantes sur la ressource
	///
	////////////////////////////////////////////////////////////
	int IResource::Release()
	{
		// D�cr�mentation du compteur de r�f�rences
		int RefCount = --m_RefCount;

		// S'il n'y a plus de r�f�rence sur la ressource, on la d�truit
		if (RefCount == 0)
		{
			delete this;
		}

		return RefCount;
	}

} // namespace GameEngine

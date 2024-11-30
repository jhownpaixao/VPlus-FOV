modded class DayZPlayerCameraBase
{

	override void StdFovUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		//! change abs FOV for naked eye zoom
		float fovMultiplier = CfgGameplayHandler.GetFOVMultiplier(); // Aumenta o FOV em 20%
		//! change abs FOV for naked eye zoom
		switch (m_pPlayer.GetEyeZoomLevel())
		{
			// ordered in likelihood of occurance for perf. reasons
			case ECameraZoomType.NONE:
				m_fFovAbsolute = Math.SmoothCD(m_fFovAbsolute, GetDayZGame().GetFOVByZoomType(ECameraZoomType.NONE) * fovMultiplier, m_fFovAbsVel, 0.1, 1000, pDt);
				break;
			case ECameraZoomType.NORMAL:
				m_fFovAbsolute = Math.SmoothCD(m_fFovAbsolute, GetDayZGame().GetFOVByZoomType(ECameraZoomType.NORMAL) * fovMultiplier, m_fFovAbsVel, 0.1, 1000, pDt);
				break;
			case ECameraZoomType.SHALLOW:
				m_fFovAbsolute = Math.SmoothCD(m_fFovAbsolute, GetDayZGame().GetFOVByZoomType(ECameraZoomType.SHALLOW) * fovMultiplier, m_fFovAbsVel, 0.1, 1000, pDt);
				break;
			default:
				m_fFovAbsolute = Math.SmoothCD(m_fFovAbsolute, GetDayZGame().GetFOVByZoomType(ECameraZoomType.NONE) * fovMultiplier, m_fFovAbsVel, 0.1, 1000, pDt);
				break;
		}

		// Aplica o FOV calculado no resultado da câmera
		pOutResult.m_fFovAbsolute = m_fFovAbsolute;
	}
}

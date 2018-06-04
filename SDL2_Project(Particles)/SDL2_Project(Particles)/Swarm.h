#pragma once
#include "Particle.h"

namespace ParticleExplosion
{
	class Swarm
	{
	private:
		Particle * m_pParticles;
		int lastTime;

	public:
		Swarm();
		virtual ~Swarm();
		void Update(int elapsed);

		const static int NPARTICLES = 5000;

		const Particle * const getParticles() { return m_pParticles; }

	};

}
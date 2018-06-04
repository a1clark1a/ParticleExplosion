#pragma once

namespace ParticleExplosion
{


	struct Particle
	{
		double m_x;
		double m_y;

		double m_speed;
		double m_direction;

		Particle();
		virtual ~Particle();
		void Update(int interval);
	};

}
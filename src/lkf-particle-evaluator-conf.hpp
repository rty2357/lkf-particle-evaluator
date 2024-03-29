/*
 * lkf-particle-evaluator-conf.hpp
 *
 *  Created on: 2012/03/14
 *      Author: tyamada
 */

#ifndef LKF_PARTICLE_EVALUATOR_CONF_HPP_
#define LKF_PARTICLE_EVALUATOR_CONF_HPP_

#include <stdint.h>
#include <ssmtype/spur-odometry.h>
#include "ssm-laser.hpp"
#include "ssm-particles.hpp"

#include "lkf-particle-evaluator.hpp"

#include "gnd-lkf.hpp"
#include "gnd-config-file.hpp"
#include "gnd-lib-error.h"


/// structure declaration
// ---> namespace lkf
namespace lkf {
	// ---> namespace peval
	namespace peval {
		/*!
		 * @brief process configuration
		 */
		struct proc_configuration;
	} // <--- namespace lkf
} // <--- namespace peval



/// function declaration
// ---> namespace lkf
namespace lkf {
	// ---> namespace peval
	namespace  peval {

		int proc_conf_initialize(proc_configuration *c);
		int proc_conf_get(gnd::conf::configuration *src, proc_configuration* dest);
		int proc_conf_set(gnd::conf::configuration *dest, proc_configuration* src);
		int proc_conf_read(const char* f, proc_configuration* dest);
		int proc_conf_write(const char* f, proc_configuration* src);

	} // <--- namespace lkf
} // <--- namespace peval


// constant definition
// ---> namespace peval
namespace lkf {
	// ---> namespace lkf
	namespace peval {

		const uint32_t uint32_max = 4294967295U;

		static const char proc_name[] = "lkf-particle-evaluator";

		// bmp-map
		static const gnd::conf::parameter_array<char, 512> ConfIni_BMPMap = {
				"bmp-map",
				"",		// file path
                                "load map with bmp map directory"
		};

		// raw-map
		static const gnd::conf::parameter_array<char, 512> ConfIni_RawMap = {
				"cnt-map-dir",
				"",		// map file directory
				"load map with counting map"
		};

		// sokuiki-raw-name
		static const gnd::conf::parameter_array<char, 512> ConfIni_SokuikiRawName = {
				"sokuiki-raw-ssm-name",
				SSM_NAME_SCAN_POINT_2D,		// ssm name
				"sokuiki raw data ssm name"
		};

		// sokuiki-raw-id
		static const gnd::conf::parameter<int> ConfIni_SokuikiRawID = {
				"sokuiki-raw-ssm-id",
				0,		// id
				"sokuiki raw data ssm id"
		};


		// sokuiki-raw-name
		static const gnd::conf::parameter_array<char, 512> ConfIni_SokuikiFSName = {
				"sokuiki-fs-ssm-name",
				"",		// ssm name
				"sokuiki fs data ssm name. if sokuiki-raw-ssm-name and id are not defined, read sokuiki fs data from ssm"
		};

		// sokuiki-raw-id
		static const gnd::conf::parameter<int> ConfIni_SokuikiFSID = {
				"sokuiki-fs-ssm-id",
				-1,		// id
				"sokuiki fs data ssm id. if sokuiki-raw-ssm-name and id are not defined, read sokuiki fs data from ssm"
		};

		// odometry-raw-name
		static const gnd::conf::parameter_array<char, 512> ConfIni_OdometryName = {
				"odometry-ssm-name",
				SNAME_ODOMETRY,		// map file directory
				"odometry data ssm name (for sleeping mode)"
		};

		// odometry-raw-id
		static const gnd::conf::parameter<int> ConfIni_OdometryID = {
				"odometry-ssm-id",
				-1,		// map file directory
				"odometry data ssm id (for sleeping mode)"
		};


		// particle-name
		static const gnd::conf::parameter_array<char, 512> ConfIni_ParticleName = {
				"particles-ssm-name",
				SNAME_PARTICLES,		// ssm name
				"particles data ssm name"
		};

		// particle-id
		static const gnd::conf::parameter<int> ConfIni_ParticleID = {
				"particle-ssm-id",
				0,		// ssm id
				"particles data ssm id"
		};


		// particle-name
		static const gnd::conf::parameter_array<char, 512> ConfIni_ParticleEvalName = {
				"particle-eval-ssm-name",
				SNAME_PARTICLES_EVALUATION,		// ssm name
				"particles evaluation data ssm name"
		};

		// particle-id
		static const gnd::conf::parameter<int> ConfIni_ParticleEvalID = {
				"particle-eval-ssm-id",
				0,		// ssm id
				"particles evaluation data ssm id"
		};

		// bmp-map
		static const gnd::conf::parameter<bool> ConfIni_Raycasting = {
				"raycasting",
				false,		// file path
				"raycasting mode"
		};


		// cycle
		static const gnd::conf::parameter<double> ConfIni_Cycle = {
				"cycle",
				0.083333,	// [s]
				"evaluation cycle"
		};

		// rest-cycle
		static const gnd::conf::parameter<double> ConfIni_SleepingTime = {
				"sleep-time",
				0.0,	// sec
				"if robot did not move, evaluation stop for this time"
		};
		// rest-threshold-distance
		static const gnd::conf::parameter<double> ConfIni_SleepingDist = {
				"sleep-threshold-distance",
				0.01,	// [m]
				"if robot did not move more than this distance, evaluation stop"
		};
		// rest-threshold-orientation
		static const gnd::conf::parameter<double> ConfIni_SleepingOrient = {
				"sleep-threshold-orientation",
				gnd_deg2rad(5),	// [rad]
				"if robot did not move more than this angle, evaluation stop"
		};


		// cull
		static const gnd::conf::parameter<double> ConfIni_CullingDist = {
				"culling-dist",
				0.05,	// [m]
				"culling parameter (distance between next reflection point)"
		};

		// cull
		static const gnd::conf::parameter<double> ConfIni_CullingRange = {
				"culling-range",
				-1,	// [m]
				"culling parameter (sensor range). if this parameter is not greater than 0, the culling range is unlimited"
		};

		// cull
		static const gnd::conf::parameter<uint32_t> ConfIni_CullingStep = {
				"culling-step",
				1,	// [m]
				"culling parameter (step)"
		};

		// blur
		static const gnd::conf::parameter<double> ConfIni_Blur = {
				"blur",
				0.05,			// [m]
		};

		// matching failure
		static const gnd::conf::parameter<double> ConfIni_ScanRangeDist = {
				"scan-range-dist",
				0,			// [m]
		};

		// matching failure
		static const gnd::conf::parameter<double> ConfIni_MatchingFailureRate = {
				"matching-failure-rate",
				0.2,
		};

		// matching failure
		static const gnd::conf::parameter<double> ConfIni_MatchingFalsePositive = {
				"matching-false-positive",
				0.05,
		};

	} // <--- namespace lkf
} // <--- namespace peval


// type definition
// ---> namespace lkf
namespace lkf {
	// ---> namespace peval
	namespace peval {

		/**
		 * @brief process configuration parameter
		 */
		struct proc_configuration {
			// initliaze input
			gnd::conf::parameter_array<char, 512>	bmp_map;			///< Bit Map
			gnd::conf::parameter_array<char, 512>	raw_map;			///< Raw Map Data
			// online input output
			gnd::conf::parameter_array<char, 512>	sokuikiraw_name;	///< Sokuiki ssm data name
			gnd::conf::parameter<int> 				sokuikiraw_id;		///< Sokuiki ssm data id
			gnd::conf::parameter_array<char, 512>	sokuikifs_name;		///< Sokuiki ssm data name
			gnd::conf::parameter<int> 				sokuikifs_id;		///< Sokuiki ssm data id
			gnd::conf::parameter_array<char, 512>	odometry_name;		///< Sokuiki ssm data name
			gnd::conf::parameter<int> 				odometry_id;		///< Sokuiki ssm data id
			gnd::conf::parameter_array<char, 512>	particle_name;		///< particles ssm data name
			gnd::conf::parameter<int>				particle_id;		///< particles ssm data id
			gnd::conf::parameter_array<char, 512>	eval_name;			///< particles evaluation ssm data name
			gnd::conf::parameter<int>				eval_id;			///< particles evaluation ssm data id
			// process behavior configuration
			gnd::conf::parameter<bool>				raycasting;			///< raycasting mode
			gnd::conf::parameter<double>			cycle;				///< evaluation cycle
			gnd::conf::parameter<double>			sleeping_time;		///< evaluation cycle in rest mode
			gnd::conf::parameter<double>			sleeping_dist;		///< criteria of rest mode (movement distance threshold)
			gnd::conf::parameter<double>			sleeping_orient;	///< criteria of rest mode (movement orient angle threshold)

			gnd::conf::parameter<double>			culling_dist;		///< reflection point cull
			gnd::conf::parameter<double>			culling_range;		///< reflection point cull
			gnd::conf::parameter<uint32_t>			culling_step;		///< reflection point cull
			gnd::conf::parameter<double>			blur;				///< scan range
			gnd::conf::parameter<double>			scan_range;			///< scan range
			gnd::conf::parameter<double>			matching_false;		///< matching failure rate
			gnd::conf::parameter<double>			false_positive;		///< false positive ratio

			proc_configuration();
		};

		/**
		 * @brief constructor
		 * @param [in/out] conf : initialized
		 */
		inline
		proc_configuration::proc_configuration() {
			proc_conf_initialize(this);
		}
	} // <--- namespace peval
} // <--- namespace lkf


// function definition
// ---> namespace lkf
namespace lkf {
	// ---> namespace peval
	namespace peval {

		/**
		 * @brief initialize process configuration structure
		 * @param [in/out] conf : initialized
		 */
		inline
		int proc_conf_initialize(proc_configuration *conf) {
			gnd_assert(!conf, -1, "invalid null pointer");

			::memcpy(&conf->bmp_map,			&ConfIni_BMPMap,				sizeof(ConfIni_BMPMap));
			::memcpy(&conf->raw_map,			&ConfIni_RawMap,				sizeof(ConfIni_RawMap));
			::memcpy(&conf->sokuikiraw_name,	&ConfIni_SokuikiRawName,		sizeof(ConfIni_SokuikiRawName) );
			::memcpy(&conf->sokuikiraw_id,		&ConfIni_SokuikiRawID,			sizeof(ConfIni_SokuikiRawID) );
			::memcpy(&conf->sokuikifs_name,		&ConfIni_SokuikiFSName,			sizeof(ConfIni_SokuikiFSName) );
			::memcpy(&conf->sokuikifs_id,		&ConfIni_SokuikiFSID,			sizeof(ConfIni_SokuikiFSID) );
			::memcpy(&conf->odometry_name,		&ConfIni_OdometryName,			sizeof(ConfIni_OdometryName) );
			::memcpy(&conf->odometry_id,		&ConfIni_OdometryID,			sizeof(ConfIni_OdometryID) );
			::memcpy(&conf->particle_name,		&ConfIni_ParticleName,			sizeof(ConfIni_ParticleName) );
			::memcpy(&conf->particle_id,		&ConfIni_ParticleID,			sizeof(ConfIni_ParticleID) );
			::memcpy(&conf->eval_name,			&ConfIni_ParticleEvalName,		sizeof(ConfIni_ParticleEvalName) );
			::memcpy(&conf->eval_id,			&ConfIni_ParticleEvalID,		sizeof(ConfIni_ParticleEvalID) );

			::memcpy(&conf->raycasting,			&ConfIni_Raycasting,			sizeof(ConfIni_Raycasting));

			::memcpy(&conf->cycle,				&ConfIni_Cycle,					sizeof(ConfIni_Cycle));
			::memcpy(&conf->sleeping_time,		&ConfIni_SleepingTime,			sizeof(ConfIni_SleepingTime));
			::memcpy(&conf->sleeping_dist,		&ConfIni_SleepingDist,			sizeof(ConfIni_SleepingDist));
			::memcpy(&conf->sleeping_orient,	&ConfIni_SleepingOrient,		sizeof(ConfIni_SleepingOrient));

			::memcpy(&conf->culling_dist,		&ConfIni_CullingDist,			sizeof(ConfIni_CullingDist));
			::memcpy(&conf->culling_range,		&ConfIni_CullingRange,			sizeof(ConfIni_CullingRange));
			::memcpy(&conf->culling_step,		&ConfIni_CullingStep,			sizeof(ConfIni_CullingStep));
			::memcpy(&conf->blur,				&ConfIni_Blur,					sizeof(ConfIni_Blur));
			::memcpy(&conf->scan_range,			&ConfIni_ScanRangeDist,			sizeof(ConfIni_ScanRangeDist));
			::memcpy(&conf->matching_false,		&ConfIni_MatchingFailureRate,	sizeof(ConfIni_MatchingFailureRate));
			::memcpy(&conf->false_positive,		&ConfIni_MatchingFalsePositive,	sizeof(ConfIni_MatchingFalsePositive));

			return 0;
		}

		/**
		 * @brief get configuration parameter
		 * @param [in]  src  : configuration parameter declaration
		 * @param [out] dest : configuration parameter
		 */
		inline
		int proc_conf_get(gnd::conf::configuration *src, proc_configuration* dest) {
			gnd_assert(!src, -1, "invalid null pointer");
			gnd_assert(!dest, -1, "invalid null pointer");

			gnd::conf::get_parameter(src, &dest->bmp_map);
			gnd::conf::get_parameter(src, &dest->raw_map);
			gnd::conf::get_parameter(src, &dest->sokuikiraw_name);
			gnd::conf::get_parameter(src, &dest->sokuikiraw_id);
			gnd::conf::get_parameter(src, &dest->sokuikifs_name);
			gnd::conf::get_parameter(src, &dest->sokuikifs_id);
			gnd::conf::get_parameter(src, &dest->particle_name);
			gnd::conf::get_parameter(src, &dest->particle_id);
			gnd::conf::get_parameter(src, &dest->odometry_name);
			gnd::conf::get_parameter(src, &dest->odometry_id);
			gnd::conf::get_parameter(src, &dest->eval_name);
			gnd::conf::get_parameter(src, &dest->eval_id);
			gnd::conf::get_parameter(src, &dest->raycasting);
			gnd::conf::get_parameter(src, &dest->cycle);
			gnd::conf::get_parameter(src, &dest->sleeping_time);
			gnd::conf::get_parameter(src, &dest->sleeping_dist);
			gnd::conf::get_parameter(src, &dest->culling_dist);
			gnd::conf::get_parameter(src, &dest->culling_range);
			gnd::conf::get_parameter(src, &dest->culling_step);
			gnd::conf::get_parameter(src, &dest->blur);
			gnd::conf::get_parameter(src, &dest->scan_range);
			gnd::conf::get_parameter(src, &dest->matching_false);
			gnd::conf::get_parameter(src, &dest->false_positive);

			if( gnd::conf::get_parameter(src, &dest->sleeping_orient) >= 0 ){
				// convert unit of angle(deg2rad)
				dest->sleeping_orient.value = gnd_deg2rad(dest->sleeping_orient.value);
			}
			return 0;
		}


		/**
		 * @brief set configuration parameter declaration
		 * @param [out] dest : configuration parameter declaration
		 * @param [in]  src  : configuration parameter
		 */
		inline
		int proc_conf_set(gnd::conf::configuration *dest, proc_configuration* src) {
			gnd_assert(!src, -1, "invalid null pointer");
			gnd_assert(!dest, -1, "invalid null pointer");

			gnd::conf::set_parameter(dest, &src->bmp_map);
			gnd::conf::set_parameter(dest, &src->raw_map);
			gnd::conf::set_parameter(dest, &src->sokuikiraw_name);
			gnd::conf::set_parameter(dest, &src->sokuikiraw_id);
			gnd::conf::set_parameter(dest, &src->sokuikifs_name);
			gnd::conf::set_parameter(dest, &src->sokuikifs_id);
			gnd::conf::set_parameter(dest, &src->odometry_name);
			gnd::conf::set_parameter(dest, &src->odometry_id);
			gnd::conf::set_parameter(dest, &src->particle_name);
			gnd::conf::set_parameter(dest, &src->particle_id);
			gnd::conf::set_parameter(dest, &src->eval_name);
			gnd::conf::set_parameter(dest, &src->eval_id);
			gnd::conf::set_parameter(dest, &src->raycasting);
			gnd::conf::set_parameter(dest, &src->cycle);
			gnd::conf::set_parameter(dest, &src->sleeping_time);

			gnd::conf::set_parameter(dest, &src->sleeping_dist);

			// convert unit of angle (rad2deg)
			src->sleeping_orient.value = gnd_rad2deg(src->sleeping_orient.value);
			gnd::conf::set_parameter(dest, &src->sleeping_orient);
			// reconvert unit of angle (rad2deg)
			src->sleeping_orient.value = gnd_deg2rad(src->sleeping_orient.value);

			gnd::conf::set_parameter(dest, &src->culling_dist);
			gnd::conf::set_parameter(dest, &src->culling_range);
			gnd::conf::set_parameter(dest, &src->culling_step);
			gnd::conf::set_parameter(dest, &src->blur);
			gnd::conf::set_parameter(dest, &src->scan_range);
			gnd::conf::set_parameter(dest, &src->matching_false);
			gnd::conf::set_parameter(dest, &src->false_positive);

			return 0;
		}

		/**
		 * @brief read configuration parameter file
		 * @param [in]  f    : configuration file name
		 * @param [out] dest : configuration parameter
		 */
		inline
		int proc_conf_read(const char* f, proc_configuration* dest) {
			gnd_assert(!f, -1, "invalid null pointer");
			gnd_assert(!dest, -1, "invalid null pointer");

			{ // ---> operation
				int ret;
				gnd::conf::file_stream fs;
				// configuration file read
				if( (ret = fs.read(f)) < 0 )	return ret;

				return proc_conf_get(&fs, dest);
			} // <--- operation
		}

		/**
		 * @brief write configuration parameter file
		 * @param [in]  f  : configuration file name
		 * @param [in] src : configuration parameter
		 */
		inline
		int proc_conf_write(const char* f, proc_configuration* src){
			gnd_assert(!f, -1, "invalid null pointer");
			gnd_assert(!src, -1, "invalid null pointer");

			{ // ---> operation
				int ret;
				gnd::conf::file_stream fs;
				// convert configuration declaration
				if( (ret = proc_conf_set(&fs, src)) < 0 ) return ret;

				return fs.write(f);
			} // <--- operation
		}

	} // <--- namespace peval
} // <--- namespace lkf


#endif /* PSM_PARTICLE_EVALUATOR_CONF_HPP_ */

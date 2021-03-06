#ifndef AK_THREAD__H
#define AK_THREAD__H

#include <pthread.h>


namespace newsbeuter {

	class thread;

	void * run_thread(void * p);

	// TODO: implement an option to provide attributes

	class thread {
		public:
			thread();
			virtual ~thread();
			pthread_t start();
			void join();

		protected:
			virtual void run() = 0;
			void detach();

			friend void * run_thread(void * p);

		private:
			static void cleanup(thread * p);
			pthread_t pt;
	};

}


#endif
